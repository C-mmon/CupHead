I am assuming the input given in the form of [2,-1,2,3,-5]
The front of the array represent the facing deck, from which either player can pick one card or two card.
Also player are aware of the entire sequence of the deck.
There is also one more assumption, both player will play optimally.
You want to maximize your score minus the opponent's score.

Player's Goal: Maximize MyScore - OpponentScore.

dp[i] definition: dp[i] = Max (MyScore - OpponentScore) I can get if the game starts at cards[i] and it's my turn.

If its my turn at cards[i].
My score immediately increases by cards[i].
Now it's the opponent's turn. The remaining cards are cards[i+1:].
Fom their perspective, they will achieve a score difference of dp[i+1]. This means if S_opp_future is the opponent's score from the rest of the game and S_my_future is my score from the rest of the game (when the opponent is making choices), then dp[i+1] = S_opp_future - S_my_future.

So, my total score at the end of the game, if I pick cards[i], will be (cards[i] + S_my_future).
The difference for me is (cards[i] + S_my_future) - S_opp_future
This can be rewritten as cards[i] - (S_opp_future - S_my_future).
and since dp[i+1] represents S_opp_future - S_my_future (the optimal difference the next player achieves), my resulting difference is cards[i] - dp[i+1].

Pick two cards (cards[i] + cards[i+1]): (This is only possible if i + 1 < n)
The current player gets cards[i] + cards[i+1].
The game moves to the state where cards from i+2 are available, and it's the other player's turn.
The other player will play optimally from cards[i+2:] and achieve a score difference of dp[i+2] from their perspective.
So, from the current player's perspective, their score difference for this choice will be (cards[i] + cards[i+1]) - dp[i+2].

`def max_score_difference_dp(cards):
n = len(cards)
if n == 0:
return 0

dp = [0] * (n + 2) 

for i in range(n - 1, -1, -1):
    # Option 1: Pick one card (cards[i])
    score_pick_one = cards[i] - dp[i+1]

    if i + 1 < n: # Can pick two cards
        score_pick_two = (cards[i] + cards[i+1]) - dp[i+2]
        dp[i] = max(score_pick_one, score_pick_two)
    else: # Only one card pick is possible (i == n-1)
        dp[i] = score_pick_one
        
return dp[0]`
