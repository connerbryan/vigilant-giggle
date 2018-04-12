function main(){

//For more help see, https://developers.google.com/adwords/scripts/docs/features/reports

    var childAccounts  = MccApp.accounts().withCondition("Name DOES_NOT_CONTAIN 'z_'").get();
    while(childAccounts.hasNext()) {
      var childAccount  = childAccounts .next()      
      MccApp.select(childAccount);
      exportName();
    }      
}

function exportName() {
    var accountName = AdWordsApp.currentAccount().getName();
    if (accountName != '') {
        Logger.log(accountName);
    }
}
