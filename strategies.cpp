#include <iostream>; 

// Control variable: generates random numbers between 0 and the number of counters the player has remaining
int trueRandom(int playerCounters){
    int bid;
    if (playerCounters == 0){ 
        bid = 0;
    }
    else { 
        bid = (rand() % playerCounters + 1); 
    }
    return bid;
       
}

// Generates random numbers within the fixed range 10-15
int aggressiveFixed(int playerCounters){
    int bid; 
    if (playerCounters == 0){ 
        bid = 0;
    }
    else if (playerCounters <= 15){ 
        bid = playerCounters; 
    }
    else { 
        bid = (rand() % 6 + 10); 
    }
    return bid;
}

// Bids 0 for the first 2 rounds, then generates random numbers between 0 and the number of counters the player has remaining
int baitAndSwitchRandom(int roundNumber, int playerCounters){ 
    int bid;
    if (roundNumber <= 2){ 
        bid = 0; 
    }
    else { 
        if (playerCounters == 0){ 
            bid = 0;
        }
        else { 
            bid = (rand() % playerCounters + 1); 
        }   
    }
    return bid; 
}

// Bids 0 for the first 2 rounds, then bids more counters than the opponent has remaining, then generates random numbers between 0 and the number of counters the player has remaining
int baitAndSwitchGuaranteeRandom(int roundNumber, int playerCounters, int opponentCounters){ 
    int bid; 
    switch (roundNumber){ 
        case 1:
        case 2:
            bid = 0; 
            break; 
        case 3:
            bid = opponentCounters + 1; 
            break; 
        default: 
        if (playerCounters == 0){ 
            bid = 0;
        }
        else { 
            if (playerCounters == 0){ 
                bid = 0;
            }
            else if (playerCounters <= 15){ 
                bid = playerCounters; 
            }
            else { 
                bid = (rand() % 6 + 10); 
            }
        }
    }
    return bid; 
}

// Bids 0 for the first 2 rounds, then bids more counters than the opponent has remaining, then generates random numbers within the fixed range 10-15
int baitAndSwitchGuaranteeAggressive(int roundNumber, int playerCounters, int opponentCounters){ 
    int bid; 
    switch (roundNumber){ 
        case 1:
        case 2:
            bid = 0; 
            break; 
        case 3:
            bid = opponentCounters + 1; 
            break; 
        default: 
        if (playerCounters == 0){ 
            bid = 0;
        }
        else { 
            bid = (rand() % playerCounters + 1); 
        }
    }
    return bid; 
}

int baitAndSwitchKiller();