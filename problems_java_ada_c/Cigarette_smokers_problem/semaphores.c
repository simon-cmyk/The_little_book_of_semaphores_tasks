// Tempting to write semaphores for all of the resources.
// This leads to deadlock ;_;

isTob = isPap = isMatch = False;
tobSem = Semaphore(0);
papSem = Semaphore(0);
matSem = Semaphore(0);
tobacco = Semaphore(0);
match = Semaphore(0);
paper = Semaphore(0);
mutex = Semaphore(1);

TobPush() {
    tobacco.wait()
    mutex.wait()
    if(isPaper){
        isPaper = False
        matSem.signal()
    } else if(isMatch){
        isMatch = False
        papSem.signal()
    } else {
        isTob = True
    }
    mutex.signal()
}

...

// Needs three pushers which will interleave Mutexlusion

// if multiples are allowed we have +=/-= instead
// Scoreboard pattern! num variables keep thrack of the 
// system state.