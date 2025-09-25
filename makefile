CC = g++
FLAG = -std=c++11

F1 = main
F2 = MerkelMain
F3 = CSVReader
F4 = OrderBook
F5 = OrderBookEntry
F6 = Wallet

all: $(F1).cpp $(F2).cpp $(F3).cpp $(F4).cpp $(F5).cpp $(F6).cpp
	$(CC) $(FLAG) $(F1).cpp $(F2).cpp $(F3).cpp $(F4).cpp $(F5).cpp $(F6).cpp -o program

clear:
	rm -rf program

