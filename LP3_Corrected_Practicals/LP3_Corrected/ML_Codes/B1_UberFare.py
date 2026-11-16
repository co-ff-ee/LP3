"""B1: Uber fare prediction using Linear Regression and Random Forest."""
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score, mean_squared_error

DATA_URL = "https://raw.githubusercontent.com/HUSSAIN-004/cl1/2c7ac4db1afcacc82fd9b4afd95b489bcd039b88/data/uber.csv"

df = pd.read_csv(DATA_URL)
df = df.drop(columns=["Unnamed: 0", "key"], errors="ignore")
df = df.dropna().copy()

# Convert pickup time into useful numeric features.
df["pickup_datetime"] = pd.to_datetime(df["pickup_datetime"], errors="coerce")
df = df.dropna(subset=["pickup_datetime"])
df["hour"] = df["pickup_datetime"].dt.hour
df["year"] = df["pickup_datetime"].dt.year
df = df.drop(columns=["pickup_datetime"])

# Remove invalid coordinates and non-positive fares.
df = df[
    df["pickup_latitude"].between(-90, 90)
    & df["dropoff_latitude"].between(-90, 90)
    & df["pickup_longitude"].between(-180, 180)
    & df["dropoff_longitude"].between(-180, 180)
    & (df["fare_amount"] > 0)
].copy()

# Haversine formula calculates approximate distance in kilometres.
lat1 = np.radians(df["pickup_latitude"])
lon1 = np.radians(df["pickup_longitude"])
lat2 = np.radians(df["dropoff_latitude"])
lon2 = np.radians(df["dropoff_longitude"])
a = np.sin((lat2 - lat1) / 2) ** 2 + np.cos(lat1) * np.cos(lat2) * np.sin((lon2 - lon1) / 2) ** 2
a = np.clip(a, 0, 1)  # Avoid floating-point values slightly outside [0, 1].
df["distance"] = 6371 * 2 * np.arcsin(np.sqrt(a))

# IQR outlier filtering for fare and distance.
for col in ["fare_amount", "distance"]:
    q1, q3 = df[col].quantile([0.25, 0.75])
    iqr = q3 - q1
    df = df[df[col].between(q1 - 1.5 * iqr, q3 + 1.5 * iqr)]

print("Dataset shape after preprocessing:", df.shape)
print("\nCorrelation with fare_amount:")
print(df.corr(numeric_only=True)["fare_amount"].sort_values(ascending=False))

X = df.drop(columns=["fare_amount"])
y = df["fare_amount"]
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

models = {
    "Linear Regression": LinearRegression(),
    "Random Forest": RandomForestRegressor(
        n_estimators=100, random_state=42, n_jobs=-1
    ),
}

for name, model in models.items():
    model.fit(X_train, y_train)
    predictions = model.predict(X_test)
    rmse = np.sqrt(mean_squared_error(y_test, predictions))
    print(f"\n{name}")
    print("R2 Score:", round(r2_score(y_test, predictions), 4))
    print("RMSE:", round(rmse, 4))
