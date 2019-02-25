#!/bin/bash
# using Angular CLI to create the module and then a default component inside (standard syntax)
ng g m modules/$1 --routing && ng g c modules/$1

# Injecting the route using my compiled cpp code. (basically injects a line and outputs results to console by default )
./injecroute src/app/app-routing.module.ts "];" "   {path: '$1', loadChildren: './modules/$1/$1.module#$2Module'}" > $1.app.routing-out.ts

# Injecting the import statement into the modules default component
./injecroute src/app/modules/$1/$1-routing.module.ts "];" "   {path: '', component: $2Component }" > $1.module-routing-outa.ts

# coping the modified file to the original angular generated file
cp $1.module-routing-outa.ts src/app/modules/$1/$1-routing.module.ts

# Injecting the a default route to the modules default component. (that was created above)
./injecroute src/app/modules/$1/$1-routing.module.ts "const routes: Routes = [" "import {$2Component } from './$1.component';" > $1.module-routing-outb.ts

# coping the second modification into the file
cp $1.module-routing-outb.ts src/app/modules/$1/$1-routing.module.ts

# Finally copy the to the apps main router file
cp $1.app.routing-out.ts src/app/app-routing.module.ts

# test your ready to route mozy loaded dule. localhost:4200/[your_new_newroute]

# Future plans
# inject the modules link to itself into an assumed navigation component [maybe pass in an optional navingation components name]
# for new just copy and paste the snippet in the file testYournav.html
echo "\<a routerLink='/$1' \>$1\</a\>" >> tesYourNav.html
#assuming a ul element exists in the navfile provided in the 3rd argument
./injectroute src/app/components/navi/navi.component.html "</ul>" "   <li><a routerLink='/$1' >$1 </li>" >> injectedLink.html
cp injectLink.html src/app/components/navi/navi.component.html
