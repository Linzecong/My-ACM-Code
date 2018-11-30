/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main{


    
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        
        int N=input.nextInt();
        BigInteger M=input.nextBigInteger();
        
        String[] name=new String[1005];
        BigInteger[] score=new BigInteger[1005];
        boolean[] vis=new boolean[1005];
        
        for(int i=0;i<N;i++){
            
            String t=input.next();
            BigInteger S=input.nextBigInteger();
            
            name[i]=t;
            score[i]=S;
        }
        
        String[] ans=new String[1005];
        int cnt=0;
        
        while(M.compareTo(BigInteger.ZERO)>0){
            int index=-1;
            BigInteger maxx=BigInteger.ZERO;
            
            for(int i=0;i<N;i++){
                if(M.compareTo(score[i])>=0){
                    
                  //  System.out.println(score[i]);
                    
                    if(score[i].compareTo(maxx)>0&&vis[i]==false){
                        index=i;
                        maxx=score[i];
                       //  System.out.println(score[i]);
                    }
                    
                }
            }
            //System.out.println(index);
            if(index==-1){
                cnt=0;
                break;
            }
            else{
               // System.out.println(cnt);
                ans[cnt]=name[index];
                cnt++;
                M=M.subtract(score[index]);
                vis[index]=true;
            }

        }
        
        if(cnt==0) {
            System.out.println(cnt);
        }
        else{
            System.out.println(cnt);
            for(int i=0;i<cnt;i++) {
                System.out.println(ans[i]);
            }
        }
        

    }
    
}
