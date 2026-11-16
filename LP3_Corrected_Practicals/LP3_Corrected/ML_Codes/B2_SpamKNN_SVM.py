"""B2: Email spam classification using KNN and SVM."""
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import (
    accuracy_score, precision_score, recall_score, f1_score,
    confusion_matrix, ConfusionMatrixDisplay
)

# Download emails.csv from the dataset specified by your practical manual.
df = pd.read_csv("emails.csv")
print("Shape:", df.shape)
print(df.head())
print("Missing values:", df.isnull().sum().sum())
print("Class distribution:\n", df["Prediction"].value_counts())

X = df.drop(columns=["Email No.", "Prediction"])
y = df["Prediction"]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# Scaling is fitted only on training data through each pipeline.
models = {
    "KNN": make_pipeline(StandardScaler(), KNeighborsClassifier(n_neighbors=5)),
    "SVM": make_pipeline(StandardScaler(), SVC(kernel="linear")),
}

comparison = []
for name, model in models.items():
    model.fit(X_train, y_train)
    predictions = model.predict(X_test)
    cm = confusion_matrix(y_test, predictions)

    print(f"\n===== {name} =====")
    print("Accuracy :", accuracy_score(y_test, predictions))
    print("Precision:", precision_score(y_test, predictions, zero_division=0))
    print("Recall   :", recall_score(y_test, predictions, zero_division=0))
    print("F1 score :", f1_score(y_test, predictions, zero_division=0))
    print("Confusion matrix:\n", cm)

    comparison.append([name, accuracy_score(y_test, predictions)])
    ConfusionMatrixDisplay(confusion_matrix=cm).plot()
    plt.title(name)
    plt.tight_layout()
    plt.show()

print("\nModel comparison:")
print(pd.DataFrame(comparison, columns=["Model", "Accuracy"]))
