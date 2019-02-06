#!/bin/bash
echo  CONSTRUCTING THE ROUTE STRING 
echo // {path: \'$1\', loadChildren: \'./modules/$1/$1.module#$2Module\'}, >> src/app/app-routing.module.ts
echo MAKING THE MODULES...
ng g m modules/$1 --routing && ng g c modules/$1
echo CONTRUCTING THE STRING FOR THE ROUTE IN THE MODULE CREATED
echo // import { $2Component } from \'./$1.component\' >> src/app/modules/$1/$1-routing.module.ts
echo // import { $2Component } from \'./$1.component\'
echo // {path: \'\', component: $2Component },
echo // {path: \'\', component: $2Component }, >> src/app/modules/$1/$1-routing.module.ts
