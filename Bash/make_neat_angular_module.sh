#!/bin/bash
echo  CONSTRUCTING THE ROUTE STRING AS A LAZY LOADED MODULE
echo // {path: \'$1\', loadChildren: \'./modules/$1/$1.module#$2Module\'}, >> src/app/app-routing.module.ts
echo MAKING THE MODULES...PLUS A DEFAULT COMPONENT...
ng g m modules/$1 --routing && ng g c modules/$1
echo CONTRUCTING THE STRING FOR THE ROUTES IN THE NEWLY CREATED MODULE CREATED
echo // import { $2Component } from \'./$1.component\'; >> src/app/modules/$1/$1-routing.module.ts
echo you will find this string added to the $2's default routing file: import { $2Component } from \'./$1.component\';
echo // {path: \'\', component: $2Component },
echo // {path: \'\', component: $2Component }, >> src/app/modules/$1/$1-routing.module.ts
echo JUST PASTE THE GENERATED TEXT IN YOUR ROUTER MODULE AND CREATED MODULE
echo YOU WILL FIND IT ALREADY SAVED IN THE FILES AS COMMENTS
