**Run the program**

> 1. run the following command, we'll get the executable file: `program`
```csh
make 
```

> 2. run the crypto currency platform by the following command

```csh
./program
```

> 3. to delete the executables, run the following command
```csh
make clear
```



**Crypto Currency Platform Guide**

1. **Starting the program**: 

   > The program read data from a CSV file (demo purpose), it also supports handling bad formatted lines.

   <img src="readme_pic/program_ui.png" alt="program running pic"/>

2. **Option 2: Print Statistics**

   > Display the statistics of supported trading pairs: **Max ask** and **min ask** 
   > The supported trading pairs are:
   >
   > 1. `BTC/USDT`
   > 2. `DOGE/BTC`
   > 3. `DOGE/USDT`
   > 4. `ETH/BTC`
   > 5. `ETH/USDT`

   <img src="readme_pic/program_ui_printStats.png" alt="print statistics pic"/>

3. **Option 3: Make an Offer** 

   > Make an offer of one of the supported trading pairs in the given format: 
   >
   > e.g. `ETH/BTC,200,0.5` 
   >
   > The system will check if the offer is valid.

   <img src="readme_pic/program_ui_makeOffer.png" alt="make offer pic"/>

   

   1. **Make an Offer- FAILURE**

      > If it fails, it means that the user doesn't have enough funds in his/hers wallet.

      <img src="readme_pic/program_ui_makeOffer_fail.png" alt="make offer failure pic"/>

      

   2. **Make an Offer- SUCCESSFUL** 

      > If it succeeds, the offer will be sent to the orderBook for future crypto currency exchange.

      <img src="readme_pic/program_ui_makeOffer_succ.png" alt="make offer successful pic"/>

   

4. **Option 4: Make a Bid**

   > It is the same as **option 3: Make an Offer** 

   

5. **Option 5: Print Wallet** 

   > Display all crypto currencies information of the user.

   <img src="readme_pic/program_ui_printWallet.png" alt="print wallet pic"/>

   

6. **Option 6: Continue** 

   > Complete all orders in the current time frame, display all matching asks/bids of the user, and go to the next time frame.

   <img src="readme_pic/program_ui_continue.png" alt="continue to the next time frame pic"/>

