use std::io::{self, prelude::*, BufWriter};
use std::str::FromStr;

#[derive(Default)]
pub struct Scanner<R> {
  reader: R,
  buffer: Vec<String>,
}

impl<R: BufRead> Scanner<R> {
  pub fn new(reader: R) -> Self {
      Self {
          reader,
          buffer: vec![],
      }
  }

  pub fn next<T: FromStr>(&mut self) -> T {
      loop {
          if let Some(token) = self.buffer.pop() {
              return token.parse().ok().unwrap();
          }
          self.buffer = self
              .next_line()
              .split_ascii_whitespace()
              .rev()
              .map(String::from)
              .collect();
      }
  }

  pub fn next_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
      (0..n).map(|_| self.next()).collect()
  }

  pub fn next_line(&mut self) -> String {
      let mut line = String::new();
      self.reader.read_line(&mut line).unwrap();
      line
  }
}

fn main() {
  let (stdin, stdout) = (io::stdin(), io::stdout());
  let mut scan = Scanner::new(stdin.lock());
  let mut out = BufWriter::new(stdout.lock());


  let t: usize = scan.next();
  for _ in 0..t {
    let (n, a, b) = (scan.next::<usize>(), scan.next::<usize>(), scan.next::<usize>());
    let mut ans = vec![];
    let mut m: usize = n;

    for _ in 1..n / 2 {
        while m == a || m == b {
            m -= 1;
        }

        ans.push(m);
        m -= 1;
    }
    ans.push(a);
    ans.push(b);

    for i in 1..=m {
        if i != a && i != b {
            ans.push(i);
        }
    }

    if *ans[0..n/2].iter().min().unwrap() != a || *ans[n/2..].iter().max().unwrap() != b {
      writeln!(out, "-1").ok();
    } else {
      for i in ans {
        write!(out, "{} ", i).ok();
      }
      write!(out, "\n").ok();
    }
  }
}