# PML
Interpreter for matrix and vector calculations.

*Suggestions are always welcome.*

## Block diagram for the project:
```
  ______________________________                 ________________________________
 |                              |               |                                |
 |           Name list          |-------------->|                                |
 |______________________________|               |                                |
         |                |                     |         Matrix Library         |
  _______|______     _____|_____                |                                |
 |              |   |           |               |                                |
 |    Parser    |---|           |               |                                |
 |______________|   | Evaluator |               |                                |
         |          |           |               |                                |
         |          |___________|               |                                |
         |                |                     |         Code for matrix        |
  _______|________________|_____                |           calculations         |
 |                              |               |                                |
 |                              |               |                                |
 |           Interface          |               |                                |
 |                              |               |                                |
 |______________________________|               |________________________________|

```
---------------------
### Interactive Manual:
```
Declaration of variables:
    Use declare keyword with syntax:

        declare: [variable1] [variable2] [...]

Initialization of variable:
    Initialize while declaration using the assignment operator '=' for each variables

Assignment of values for variables:
    Assign values for variables using the assignment operator '='using the syntax:
    Syntax for matrices:

        variable = 
                   [value] [value] [...  ]
                   [value] [value] [...  ]
                   [...  ] [...  ] [...  ]

Performing operations:
    Unary operators:
    
        [variable]' -----------------------------------> Puts thetranspose into the same variable
        [variable1] = [variable2]'
    Binary operators:

        [variable1] + [variable2] ---------------------> Puts thesum into [variable1]
        [variable1] = [variable2] + [variable3]

    -Other binary operators(-, *) share the same syntax.

Display a variable:
    Use display keyword with the syntax:
    
        display: [variable1] [variable2] [...]
```
----------------------
