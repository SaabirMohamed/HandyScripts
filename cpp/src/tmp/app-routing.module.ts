import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

const routes: Routes = [
  {path: 'pnf', loadChildren: './modules/login/login.module#LoginModule'},
  {path: 'contact', loadChildren: './modules/contact/contact.module#ContactModule'},
  {path: 'about', loadChildren: './modules/about/about.module#AboutModule'},
  {path: 'signup', loadChildren: './modules/signup/signup.module#SignupModule'},
  {path: 'hadith', loadChildren: './modules/hadith/hadith.module#HadithModule'},
  {path: '', pathMatch: 'full', loadChildren: './modules/login/login.module#LoginModule'},
  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

// 
