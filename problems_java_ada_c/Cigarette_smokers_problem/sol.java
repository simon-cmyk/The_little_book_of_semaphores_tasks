class Table() {
    private tob = False
    private match = False
    private pap = False

    synchronized tobacco() {
        tob = True;
        notifyAll();
    }

    ...

    synchronized tobaccoSmoker() {
        while(!match and !pap) {wait();}
        match = False;
        pap = False; 
        notifyAll();
    }

    ...

    synchronized emptyTable(){
        while(one nonempty) wait();
        // Place two of em
    }
}