# Some handy custom scripts and programs I wrote.

## Whats in here...
1. Bash/... shell scripts
2. Cpp/... C++ programs and tools


### Instructions for the bash script: 
` make_a_neat_angular_module.sh ` 
> In your terminal just pass in the module name twice once in all lower case and once capitalised. you should also run this from the cloned folder
```
 ln -s /fullPathToScript.sh mmm && sudo chmod +x /usr/local/bin/mmm
 
 ```
> This creates a link for convenience... now you can modify and save the source file and "mmm" will be the way you execute the command , please note that you must be in the root folder of your angular project
``` 
$ mmm home Home // where home is the name of the lazy module

```
#### This is what the script does
* creates the module with angular cli's routing flag
* creates a component which acts as the default loaded component (my usual pattern)
* appends the default app-routing.module.ts file with the constructed string for a lasy loaded module.
 ```
 { path: 'home', loadChildren: 'modules/home/home.module#HomeModule'}
 ```
 these generated strings which you will normally have to navigate around the project to type out manually are appended as comments at the bottom of the target files for now (you can just cut and paste and you done)
* finally it generates the "comment" in the module route with 
```
import {HomeComponent} from './home.component';
{path: '', component: HomeComponent}

```

### Instrctions for programs the cpp folder:
1. ` wrapEachLineInHtml.cpp and the binary ./wrapEachLineInHtml `  
* Syntax : ` $./wrapEachLineInHtml /<div/> /<p/> `
2. ` wrapEachWordInHtml.cpp and the binary ./wrapEachWordInHtml `
* Syntax : ` $./wrapEachWordInHtml /<div/> /<p/> `
  
> Yes, you must pass it in the command line exactly like that(for now) with escape chars   
Will Update the code ... handle just div, p, span, td,  [so any tag can be used even custom components] 
maybe concat to the past in args in the cpp....later

#### The files in this repo are just for my specific use cases (others may find them handy too )



