/* bool a_star_algorithm(string now, int step) {
  int row, col;
  int tmp;
  int ans = 0;
  int run = 0;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      tmp = (now[run*2] - '0')*10 + (now[run*2+1] - '0');
      row = tmp / 4 + 1;
      col = (tmp % 4 == 0) ? 4 : tmp % 4;
      if (tmp == 0) row = 4, col = 4;
      ans += (abs(row-i) + abs(col-j));
      //if (row == i && col != j) ans += 2;
      //if (row != i && col == j) ans += 2;
      run += 1;
    }
  }
  if (ans / 2 > step) return false;
  return true;
} */

/* bool recur(string now, int step, int row, int col) {
  if (now == ans) return true;
  else if (step <= 0) return false;
  
  if (!a_star_algorithm(now, step)) return false;
  bool flag = false;
  if (row + 1 < 4) {
    string next = down(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row+1, col);
      m[next] = 0;
    }
  } if (row - 1 >= 0) {
    string next = up(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row-1, col);
      m[next] = 0;
    }
  } if (col + 1 < 4) {
    string next = right(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row, col+1);
      m[next] = 0;
    }
  } if (col - 1 >= 0) {
    string next = left(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row, col-1);
      m[next] = 0;
    }
  }
  return flag;
} */

//cout << start << endl;

  /* for (int i = 0;; i++) {
    if (recur(start, i, row, col)) {
      cout << i << endl;
      return 0;
    }
    cout << i << endl;
  } */