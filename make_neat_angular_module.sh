#####################################################################################
# This code is provided as is and I except no responsibilty for mis-use of this code.
# Author: Saabir Mohamed
# ###################################################################################
# REASON: Lesson boilder plate as much as possible (for Angular )
# How this script Runs
# I create a module and place it in the modules folder in the src/app/ folder this is defalt path behaviour
# it makes the module , creates a default route component angular then updates the closest module.
# make sure when running the command you are in the apps root folder example: myapp/...
##################################################
# STEP 1. create the module in the modules folder 
# STEP 2. navigate to it and create a default component of the same name (usually my pattern)
# STEP 3. goback to the app root folder 
# #####################################
# Creating the default route is tricky because of the angular boilerplate
# so I just create the routes as end of file comments that you can cut and paste after
# this next command is relative the routing module file...
# The module name in the loachildren area requires that it be Capitalized so I just quickly pass the module name in twice 
# like this 
# COMMAND IN YOUR TERMINAL : ./make__neat_angular_module.sh login Login
# (you pass the name of the module once in lower and once with the first letter Capitalised
# I know that a python or some other script can be used to capitalize the variable but 
# this is inside a bash so its just quicker then writing more code
# CONSTRUCTING THE ROUTE STRING 
echo // {path: '$1', loadChildren: '../modules/$1/$1.module#$2Module'}, >> src/app/app-routing.module.ts
# you still need a string in the component which is default to the module...
ng g m modules/$1 --routing && cd src/app/modules/$1 && ng g c $1 && cd ../../../../
# CONTRUCTIN THE STRING FOR THE ROUTE IN THE MODULE CREATED
echo // import { %1Component } from './$1.component' >> src/app/modules/$1/$1-routing.module.ts
echo // import { %1Component } from './$1.component'
echo // {path: '', component: $1Component },
echo // {path: '', component: $1Component }, >> src/app/modules/$1/$1-routing.module.ts
