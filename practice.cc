#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>



int main(){
    int x;
    double D[1000];
    double E[1000];
    int a,c;
    int b=0;
    int i=0;
    std :: string str[1000];
    double ans;

    std :: cout << "0:計算を始める,1:計算をしない"<< std :: endl;
    std :: cin >> a;

   

    while(a!=1){  //aの値が1でなければ計算を続ける
      std ::string S="=";
      i=0;
      ans=0;
      c=0;
      do{
        std :: cout << "値を入力してください" << std :: endl;
        std :: cin >> D[i];
        std :: cout << "演算記号を入力してください"<< std :: endl;
        std :: cin >> str[i];
        i++;
      }while(0==(str[i-1]==std :: string("=")));//=が入力されるまで式の記入を続ける
      c=i;
      
      for(i=0; i<c;i++){
       

        if(0==(str[i].compare("*"))){//str[i]に*が格納されているか
          
          
          if(0==(str[i-1].compare("+"))){//str[i-1]に+が格納されているか

            if((0==(str[i+1]).compare("/")) || 0==(str[i+1].compare("*"))){//str[i+1]に/または*が入っているか

              ans=D[i]*D[i+1];//"/"または"*"が格納されていない場合D[i]*D[i+1]の結果をansへ格納

            }else{

              E[i]=D[i] * D[i+1];//"/"または"*"が格納されている場合はE[i]へと結果を格納

              }
            
          }else if(0==(str[i-1].compare("-"))){//str[i-1]に-が格納されているか

            if((0==(str[i+1]).compare("/")) || (0==(str[i+1].compare("*")))){
             
              if((D[i]>0 && D[i+1]>0) || (D[i]<0 && D[i+1]<0)){

                ans=D[i]*D[i+1]*-1;
              
              }else{
              
                ans=D[i]*D[i+1];
              
              }
            
            }else{
            
              if((D[i]>0 && D[i+1]>0) || (D[i]<0 && D[i+1]<0)){
                
                E[i]=(D[i] * D[i+1])*-1;
              
              }else{
              
                E[i]=D[i] *D[i+1];
              
              }
            }
          }else if(0==(str[i-1].compare("/"))){

          ans=ans * D[i+1];
          
          }else if(0==(str[i-1].compare("*"))){

          ans=ans * D[i+1];
          
          }else{

          ans=D[i] * D[i+1];
        
        }
      }

        
        if(0 ==(str[i].compare("/"))){

          

          if(0==(str[i-1].compare("+"))){

            if((0==(str[i+1]).compare("/")) || 0==(str[i+1].compare("*"))){

              ans=D[i]/D[i+1];
              
            }else{
              
            E[i]=D[i]/D[i+1];
            
            }
          }else if(0==(str[i-1].compare("-"))){

            if((0==(str[i+1]).compare("/")) || 0==(str[i+1].compare("*"))){
              
              if((D[i]>0 && D[i+1]>0) ||(D[i]<0 && D[i+1]<0)){
                
                ans=(D[i]/D[i+1] )* -1;

              }else{

                ans=(D[i]/D[i+1]);

              }

            }else{
             
              if((D[i]>0 && D[i]>0) ||(D[i]<0 && D[i+1]<0)){
                
                E[i]=(D[i]/D[i+1]) * -1;
              
              }else{
              
                E[i]=(D[i]/D[i+1]);
              
              }
            }
          }else if(0==(str[i-1].compare("*"))){
          
            ans=ans/D[i+1];
            
          } else if(0==(str[i-1].compare("/"))){
          
            ans=ans/D[i+1];
          
          }else {

             ans= D[i]/D[i+1];
          }
        
        }
      }

     
      for(i=0;i<c+1;i++){
        ans =ans+E[i];
      }
     
       
      
      for(i=0; i<c;i++){
        if(0==(str[i].compare("+"))){
          
           if((0==(str[i-1].compare("*"))) || 0==(str[i-1].compare("/"))){

              ans= ans + D[i+1];

            if((0!=(str[i+2].compare("*")))||0!=(str[i+2].compare("/"))){

              ans= ans - D[i+1];

            }

          }else if((0==(str[i+1].compare("*"))) || 0==(str[i+1].compare("/"))){
        
            
            ans = ans + D[i];

            if(0==(str[i-1].compare("-"))){

              ans =ans-D[i];

            }
          
          }else if((0==(str[i-1].compare("+")))||(0==(str[i-1].compare("-")))){

            ans=ans + D[i+1];

          }else {

            ans = D[i]+D[i+1];

          }
        
        }else if(0==(str[i].compare("-"))){

          if((0==(str[i+1].compare("*"))) || 0==(str[i+1].compare("/"))){

            if(((D[i+2]<0) && (D[i+1<0]))){
              
              ans=D[i]+ans;
              
              ans=ans-D[i+1];

            }else if((((D[i+2]<0) && (D[i+1]>0)) || ((D[i+2]>0) && (D[i+1]<0)))){

              ans=D[i]-ans;
              
              ans=ans-D[i+1];

            }
            if((0!=(str[i+2].compare("*")))||0!=(str[i+2].compare("/"))){

              ans= D[i+1]+ans;

            }

          }else if((0==(str[i-1].compare("*"))) || 0==(str[i-1].compare("/"))){
            
            ans-=D[i+1];

          }else if((0==(str[i-1].compare("+")))||(0==(str[i-1].compare("-")))){

            ans=ans - D[i+1];

          }else{
            ans =D[i]-D[i+1];
          }

        }
      }

     

      std :: cout << "ans=" << ans << std :: endl;

      for(i=0;i<c+1;i++){
        E[i]=0;
      }
    

    std :: cout << "0:計算を続ける,1:計算を終了する" << std :: endl;
    std :: cin >> a;
    
 
    }
  std :: cout << "終了" << std :: endl;  
 return 0;
  }