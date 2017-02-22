Source code for the stochastic simulation program. It should compile with any C compiler. The command-line parameters are:

 
aleae <file1> <file2> <trials> <time> <verbosity> <output file specified by user>
 
where <file1>     contains the name, initial quantity and threshold for each molecular type
<file2>     contains the reactants, products and rate constant for each reaction
<trials>    specifies how many trials to perform
<time>      specifies a time limit (this is if random time steps are taken -- set it to -1 to ignore time)
<verbosity> specifies how detailed the output should be; choose a number between 0 and 15, inclusive.
<output file> the output file specified by the user

1. Question A
Input files: 1. question_a.in(initial state and conditions for the probabilities we need to find) 
		2.question_a.r(reaction definitions)
Output file: question_a.out (or any filename specified by user)

sample command: > ./aleae p1.in p1.r 1000 100 0 p1.out

Test steps:
1. make clean
2. make
3. pass the following command 
> ./aleae p1.in p1.r 1000 100 0 p1.out
to the command line
4. check the p1.out generated

2. Question B
Input files: 1. question_b.in 2. question_b.r
Output file: temp.out(temporary output, variance to be computed)

Test steps:

1. make clean
2. make
3. pass the following command 
> ./aleae question_b.in question_b.r 1000 0.0114 8 temp.out 
to the command line
4. pass another command 
> ./CalculateVariance temp.out 
and execute, a new file called question_b.out has been generated
5. check mean and variance from the question_b.out