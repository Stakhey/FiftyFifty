#include <iostream> 

int main(){ 
    // Initialise Counters, Flags And Shell Position
    int playerCounters {50};
    int compCounters {50};
    bool gameLoop {true}; 
    bool validBid {true}; 
    bool zeroCheck {true}; 
    int shellPosition {0};
    srand(time(NULL)); 

    while (gameLoop) { 

        std::cout << "You have " << playerCounters << " counters" << std::endl;
        std::cout << "The computer has " << compCounters << " counters" << std::endl;

        // Player Bid
        int playerBid; 
        while (validBid){
            std::cout << "Enter a bid: " << std::endl;
            std::cin >> playerBid; 
            if (playerBid > playerCounters){ 
                std::cout << "Not enough counters! ";
            }
            else { 
                playerCounters -= playerBid;
                validBid = false; 
            }
        }
        validBid = true;
        
        int compBid;
        // Computer Bid
        if (compCounters == 0){ 
            compBid = 0;
        }
        else { 
            compBid = (rand() % compCounters+1); 
        }
        compCounters -= compBid;

        std::cout<< "You bid " << playerBid << std::endl;
        std::cout<< "The computer bid " << compBid << std::endl;

        // Player Bid vs Computer Bid Calculations
        if (playerBid > compBid){ 
            std::cout << "You win the bid!" << std::endl; 
            shellPosition++;
        }
        else if (compBid > playerBid){ 
            std::cout << "Computer wins the bid!" <<std::endl; 
            shellPosition--;
        }
        else { 
            std::cout << "Draw!";
        }   

        std::cout << "The shell is at position " << shellPosition << std::endl; 

        // End Of Bidding Round Checks
        if (shellPosition  == 3){ 
            std::cout << "YOU WIN!" << std::endl; 
            gameLoop = false;
            zeroCheck = false;
        }
        else if (shellPosition == -3){ 
            std::cout << "COMPUTER WINS!" << std::endl; 
            gameLoop = false; 
            zeroCheck = false;
        }

        if (zeroCheck){ 
            if ((playerCounters == 0) && (compCounters == 0)){ 
                std::cout << "Both players are unable to bid further! DRAW!";
                gameLoop = false;
            }
        }
    }
}