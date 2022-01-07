# Tic-Tac-Toe
Implementation of AI bot for a two-player game 

<img align="left" alt="Visual Studio Code" width="820px" height="720px" src="https://github.com/harshithvh/Tic-Tac-Toe/blob/main/images/img-1.jpg" />

# Description

---

A game is an activity among two or more independent decision-makers seeking to achieve their objectives in some limiting context. Games in medieval times required at least two players. This is a problem, as you are dependent on other players. This problem was solved by modern video games, in which developers made games for single players. But the opponents in those games were not too smart and thus games didn’t have a wider audience. Games of today use some kind of bots with intelligence as opponents. The inclusion of these AI bots made the games engaging and they are loved by wider audiences. Today we will see how these bots are made, and we will create an AI bot for a two-player game (Tic-Tac-Toe).

# Different ways to create game bots

---

There are multiple ways to create bots for games like:

1. Making Random moves

Moves will be artificial but will lack intelligence thus the game will not be engaging

2. Finding Probability of Winning, Losing, and Draw with all possible moves

In this, we use data. the bot will play games in simulation and calculate the number of wins, losses and draw matches and will perform the move with more win% or draw%.

# Min-Max Algorithm

---

Min-Max is an algorithm that is used in decision making and game theory.
It is generally used in two-player games, in which one player will try to maximise the score, and the other will try to minimize the score.
Min-Max algorithm is optimal if a player plays optimally. The solution is guaranteed if exist. 
The player will receive a reward if the game reached an end state. 
