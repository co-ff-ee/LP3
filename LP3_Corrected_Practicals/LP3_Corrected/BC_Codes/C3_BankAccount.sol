// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    address public owner;
    uint256 private balance;

    constructor() {
        owner = msg.sender;
    }

    function deposit() public payable {
        require(msg.value > 0, "Send some ETH");
        balance += msg.value;
    }

    function withdraw(uint256 amount) public {
        require(msg.sender == owner, "Only owner can withdraw");
        require(amount > 0, "Amount must be greater than zero");
        require(amount <= balance, "Insufficient balance");

        // Update state before making the external call.
        balance -= amount;
        (bool sent, ) = payable(owner).call{value: amount}("");
        require(sent, "Transfer failed");
    }

    function getBalance() public view returns (uint256) {
        return balance;
    }
}
