# Some handy custom scripts and programs I made.
#### 1.) Angular 2 to 7, Lazy module maker
#### 2.) c++ console app that wraps divs' spans' p elements around lines or words in a file. 

## Whats in here... [Tested and using on Mojave]
1. bash/... shell scripts I will place in here
2. cpp/... C++ programs and tools

### Instructions for the bash script: 
` make_a_neat_angular_module.sh ` 
> In your terminal just pass in the module name twice once in all lower case and once capitalised. you can also run this from the cloned folder
```
 ln -s make_a_neat_angular_module.sh /usr/local/bin/mmm && sudo chmod +x /usr/local/bin/mmm
 
 ```
> This creates a link for convenience... now you can modify and save the source file and "mmm" will be the way you execute the command , please note that you must be in the root folder of your angular project,
``` 
$ mmm home Home // where home is the name of the lazy module you want to create with routing and route strings all done!

```

> or [new Feature 25-02-2019], This assumed for now that you have some html file diplaying your navigations in a <ul> element. [it appends html to that file where it finds the ul elements], so you dont have to creat the link

```
mmm home Home path_to_your_html_navigation

```

#### This is what the script does

* creates the module with angular cli's routing flag [basically this : ng g m home --routing]
* creates a component which acts as the default loaded component inside the new lazy loaded module [ng g c modules/home] 
* appends the default app-routing.module.ts file with the constructed string for a lazy loaded module's route path. so you dont h...a...v...e  t..o  t...y...p...e  o...u...t  s...o  m...u...c...h boilerplate code.
* and finally puts a link in the ul's that you have in some navigation component

 ```
 { path: 'home', loadChildren: 'modules/home/home.module#HomeModule'} // back in the day I had to manually do this for each module.
 ```
 these generated strings which you will normally have to navigate around the project to type out manually are appended as comments at the bottom of the target files for now (nothing fancy, you can just cut and paste and you done)
* finally appends this to the modules root component 
```
import {HomeComponent} from './home.component';
{path: '', component: HomeComponent}

```

### Instructions for programs the cpp folder:
1. ` wrapEachLineInHtml.cpp and the binary ./wrapEachLineInHtml `  
* Syntax : ` $./wrapEachLineInHtml /<div/> /<p/> `
2. ` wrapEachWordInHtml.cpp and the binary ./wrapEachWordInHtml `
* Syntax : ` $./wrapEachWordInHtml /<div/> /<p/> `
  
> Yes, you must pass it in the command line exactly like that(for now) with escape chars   
Will Update the code ... handle just div, p, span, td,  [any tag can be used even custom components] 
maybe concat to the past in args in the cpp....later 

#### The files in this repo are just for my specific use cases (others may find them handy too please use at 
### your own risk as this scripts modify your default cli generated files.)

### Instructions for programs the misc folder:
#### Just some handy files and scripts I keep around to quikly reset ethernet connection
#### fix screen resolution problem on mac vm (works on Mojave and Calalina)

