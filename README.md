# Some handy scripts I made for   day to day coding.

## Whats in here...
1. Inside Bash/.. --> make_a_neat_angular_module.sh (you can make the name smaller.)
2. Indide Cpp/.. --> PutTextInDiv reads a file called "qsource.txt" and puts each line in a div and its text in a p elelment cpp programs (the bin and the source)


### How to :
> In your terminal just pass in the module name twice once in all loawer case and once capitalised. you should also run this from the cloned folder
``` ln -s /fullPathToScript.sh mmm && sudo chmod +x /usr/local/bin/mmm ```
> This creates a link for convenience ,,,, now you can use it like this, please note that you must be in the root folder of you angular project
``` 
$ mmm home Home // where home is the name of the lazy module

```
* creates the module with angular cli's routing flag
* creates a component which acts as the default loaded component (my usual pattern)
* appends the default app-routing.module.ts file with the constructed string for a lasy loaded module. `{ path: 'home', loadChildren: 'modules/home/home.module#HomeModule'}` this is appended as a comment for now (you can just cut and paste and you done)
* finally it generates the "comment" in the module route with 
```import {HomeComponent} from './home.component';
   {path: '', component: HomeComponent}
```





