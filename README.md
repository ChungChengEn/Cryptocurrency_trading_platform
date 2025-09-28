# Cryptocurrency Trading Platform

A C++ console-based cryptocurrency trading simulation platform that allows users to place buy/sell orders, manage their digital wallet, and interact with a simulated order book using real market data.

## 🚀 Features

- **Interactive Trading Interface**: Console-based menu system for easy navigation
- **Order Management**: Place ask (sell) and bid (buy) orders with real-time validation
- **Digital Wallet**: Manage multiple cryptocurrency balances with automatic transaction processing
- **Order Book Simulation**: Advanced matching algorithm that pairs buyers and sellers
- **Market Statistics**: Real-time market data analysis and price tracking
- **CSV Data Processing**: Load and process historical trading data from CSV files
- **Time-based Simulation**: Step through different timeframes to simulate market progression

## 📋 Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Core Components](#core-components)
- [Trading Flow](#trading-flow)
- [Data Format](#data-format)
- [Building](#building)

## 🔧 Installation

### Prerequisites

- C++ compiler with C++11 support (g++, clang++)
- Make utility
- CSV data file (`CSV_orderbook_data.csv`)

### Building the Project

```bash
# Clone the repository
git clone https://github.com/ChungChengEn/cryptocurrency-trading-platform.git
cd cryptocurrency-trading-platform

# Build using make
make

# Run the program
./program
```

### Clean Build

```bash
make clear  # Remove compiled binaries
make        # Rebuild
```

## 🎮 Usage

### Main Menu Options

When you run the program, you'll see a menu with the following options:

1. **Print Help** - Display trading guidance and objectives
2. **Print Exchange Stats** - View current market statistics for all products
3. **Make an Offer** - Place a sell order (ask)
4. **Make a Bid** - Place a buy order (bid)
5. **Print Wallet** - Display current cryptocurrency balances
6. **Continue** - Advance to the next timeframe and process trades

### Making Trades

#### Placing a Sell Order (Ask)
```
Format: product,price,amount
Example: ETH/BTC,0.034,2.5
```

#### Placing a Buy Order (Bid)
```
Format: product,price,amount
Example: ETH/BTC,0.033,1.0
```

### Example Trading Session

```
Current time is: 2020/03/17 17:01:24.884492
1: Print help 
2: Print exchange stats
3: Make an offer 
4: Make a bid 
5: Print wallet 
6: Continue 
===============
Type in 1-6
```

## 📁 Project Structure

```
├── main.cpp              # Application entry point
├── MerkelMain.h/cpp      # Main application controller
├── OrderBook.h/cpp       # Order book management and matching
├── OrderBookEntry.h/cpp  # Individual order representation
├── Wallet.h/cpp          # Digital wallet management
├── CSVReader.h/cpp       # CSV file parsing utilities
├── makefile              # Build configuration
└── CSV_orderbook_data.csv # Market data (not included)
```

## 🔧 Core Components

### MerkelMain
- **Purpose**: Main application controller and user interface
- **Key Features**:
  - Interactive menu system
  - User input validation
  - Order placement workflow
  - Trading simulation coordination

### OrderBook
- **Purpose**: Manages all trading orders and executes matching logic
- **Key Features**:
  - Order storage and retrieval
  - Advanced matching algorithm (asks to bids)
  - Price-time priority matching
  - Historical data management

### Wallet
- **Purpose**: Digital cryptocurrency wallet management
- **Key Features**:
  - Multi-currency support
  - Balance validation
  - Transaction processing
  - Order fulfillment checking

### OrderBookEntry
- **Purpose**: Represents individual trading orders
- **Supported Types**:
  - `ask` - Sell orders
  - `bid` - Buy orders
  - `asksale` - Completed sell transactions
  - `bidsale` - Completed buy transactions

### CSVReader
- **Purpose**: Handles CSV data parsing and order creation
- **Key Features**:
  - Robust CSV parsing
  - String tokenization
  - Data validation
  - Order book entry creation

## 🔄 Trading Flow

1. **Initialization**
   - Load historical data from CSV
   - Initialize wallet with starting balance (10 BTC)
   - Set current timestamp to earliest data point

2. **Order Placement**
   - Validate user input format
   - Check wallet balance sufficiency
   - Add order to order book
   - Sort orders by timestamp

3. **Order Matching**
   - Retrieve all asks and bids for current timeframe
   - Sort asks (lowest price first) and bids (highest price first)
   - Match compatible orders using price-time priority
   - Generate sale transactions

4. **Transaction Processing**
   - Update wallet balances for completed trades
   - Process both incoming and outgoing currencies
   - Log transaction details

## 📊 Data Format

### CSV Input Format
```
timestamp,product,order_type,price,amount
2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187305,17.90740000
```

### Supported Products
- ETH/BTC (Ethereum/Bitcoin)
- DOGE/BTC (Dogecoin/Bitcoin)
- And other cryptocurrency pairs in your data

## 🏗️ Building

### Compiler Requirements
- C++11 standard or higher

### Build Process
```bash
# Debug build
g++ -std=c++11 -g main.cpp MerkelMain.cpp CSVReader.cpp OrderBook.cpp OrderBookEntry.cpp Wallet.cpp -o program

# Release build
g++ -std=c++11 -O2 main.cpp MerkelMain.cpp CSVReader.cpp OrderBook.cpp OrderBookEntry.cpp Wallet.cpp -o program
```

## 🧪 Testing

The platform includes built-in validation for:
- Input format verification
- Balance sufficiency checking
- Order matching logic
- Wallet transaction integrity


## 🙏 Acknowledgments

- Market data simulation concepts
- C++ best practices and design patterns
- Open source trading platform inspirations

---
