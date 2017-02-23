Source code for the stochastic simulation program. It should compile with any C compiler. The command-line parameters are:

 
aleae <file1> <file2> <trials> <time> <verbosity> <output file specified by user>
 
where <file1>     contains the name, initial quantity and threshold for each molecular type
<file2>     contains the reactants, products and rate constant for each reaction
<trials>    specifies how many trials to perform
<time>      specifies a time limit (this is if random time steps are taken -- set it to -1 to ignore time)
<verbosity> specifies how detailed the output should be; choose a number between 0 and 15, inclusive.
<output file> the output file specified by the user

1. Question 1
Input files: 1. p1.in(initial state and conditions for the probabilities we need to find) 
		2.p1.r(reaction definitions)
Output file: p1.out (or any filename specified by user)

sample command: > ./aleae p1.in p1.r 10 10000 0 p1.out

Test steps:
1. make clean
2. make
3. pass the following command 
> ./aleae p1.in p1.r 10 10000 0 p1.out
to the command line
4. check the p1.out generated

2. Question 2
Input files: 1. p2.in 2. p2.r
Output file: p2.out

Test steps:

1. make clean
2. make
3. pass the following command 
> ./aleae p2.in p2.r 17 1e9 0 p2.out 
to the command line
4. check mean and variance from the p2.out