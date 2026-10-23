
//pseudo code of peterson solution


bool flag[2] = {false, false};
int turn;

// For process Pi:
// i = 0 or 1
// j = 1 - i

flag[i] = true;  // I want to enter
turn = j;        // Give the other process priority

while (flag[j] && turn == j) {
    // Busy waiting
}

// Critical section

flag[i] = false;

// Remainder section
