# Political-System-CPP
This C++ project is a simulation of a multi-party political election system. The system allows multiple political parties to participate, each affiliating with one of two major factions: Republicans or Democrats. Politicians, who also belong to one of these two factions, have unique roles and abilities.

There are two categories of politicians, each with specific capabilities: Leader politicians who can lead a political party, and Social politicians who can amplify their party's strength during elections.

The political system supports elections at any time, consisting of two main phases:

Primaries: In this phase, each party selects its most influential Leader politician to represent them, and updates the identity of all their politicians.
Elections: During elections, the strength of each party is compared, and the party with the highest strength wins, appointing its Leader politician as the head of government.
To facilitate communication between parties and politicians, the Observer design pattern is employed.
