//http://usaco.org/index.php?page=viewproblem2&cpid=1179
#include <bits/stdc++.h>
using namespace std;

int main() {
  char grid[3][3],guess[3][3];

  string s;
  int es[26]={0};
  for(int i=0;i<3;i++) {
    cin >> s;
    grid[i][0] = s[0];
    grid[i][1] = s[1];
    grid[i][2] = s[2];
    es[s[0]-'A']++;
    es[s[1]-'A']++;
    es[s[2]-'A']++;
  }
  for(int i=0;i<3;i++) {
    cin >> s;
    guess[i][0] = s[0];
    guess[i][1] = s[1];
    guess[i][2] = s[2];
  }
  int green=0;
  int yellow=0;
  
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if (grid[i][j] == guess[i][j]) {
        green++;
        es[grid[i][j]-'A']--;
      }
    }
  }
  //we need to separate as two loops to check the yellows
  //since the gree may use all the elements
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if (grid[i][j] != guess[i][j]) {
        if (es[guess[i][j]-'A']>0) {
        yellow++;
        es[guess[i][j]-'A']--;
      }
    }
  }
  }
  cout<<green<<endl;
  cout<<yellow;
}

/*
public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String correct = in.readLine() + in.readLine() + in.readLine();
        String guess = in.readLine() + in.readLine() + in.readLine();
        int[] freqCorrect = new int[26];
        int[] freqGuess = new int[26];
        int green = 0;
        for (int j = 0; j < 9; j++) {
            if (correct.charAt(j) == guess.charAt(j)) {
                green++;
            }
            freqCorrect[correct.charAt(j) - 'A']++;
            freqGuess[guess.charAt(j) - 'A']++;
        }
        int yellow = 0;
        for (int j = 0; j < 26; j++) {
            yellow += Math.min(freqCorrect[j], freqGuess[j]);
        }
        yellow -= green;
        System.out.println(green);
        System.out.println(yellow);
    }
*/
