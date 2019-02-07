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
* creates the module with angular cli's routing flag
* creates a component which acts as the default loaded component (my usual pattern)
* appends the default app-routing.module.ts file with the constructed string for a lasy loaded module.
 ```
 { path: 'home', loadChildren: 'modules/home/home.module#HomeModule'}
 ```
 these generated strings which you will normally have to navigate around the project to type out manually are appended as a comments at the botton of the target files for now (you can just cut and paste and you done)
* finally it generates the "comment" in the module route with 
```
import {HomeComponent} from './home.component';
{path: '', component: HomeComponent}

```

### Instrctions for the cpp program:
` PutTextInDiv ` 

> Put text into a file name it qsource.txt when the program is run it will wrap whatever html you want around each line. [soon i will make it except params for csv genration or other wraps] for now just use the source file as qsource.txt and pipe out to a file using `>> filename.html `.
```
$./PutTextInDiv >> html_version.html

```



