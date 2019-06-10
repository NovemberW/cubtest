# cubtest
A portable, open source test framework for C

Cubtest ist derived from the urgent need for a C-Test framework for
the Cubesat currently under development by the TU Darmstadt Space Technology e. v. (http://tudsat.space/).

After evaluating available open source solutions we found it to be easier to write a new one that is tailored to our needs.

Combined with our strict open source (& knowledge) philosophy, it was decided to outsource 
the framework into a separate project and as such make it available under GPL v3.

Cubtest is meant to provide a very simple and usable approach to the problem of testing in C,
especially on embedded platforms such as CubeSats.

Q: Sure, but what can it do ?

A: It can:

- Provide a wide variety of asserting Functions
- Provide the basic scheme for reports of test runs
- Make it easier to use problem specific automation solutions

And most important of all 

- Be easy to adapt to your project


Within the example/ directory you can find a simple demonstrator that can be run on a desktop pc.
