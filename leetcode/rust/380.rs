use std::collections::HashSet;
use rand::{Rng, prelude::IteratorRandom};


struct RandomizedSet {
    set: HashSet<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        RandomizedSet {
            set: HashSet::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        self.set.insert(val)
    }

    fn remove(&mut self, val: i32) -> bool {
        self.set.remove(&val)
    }

    fn get_random(&self) -> i32 {
        let mut rng = rand::thread_rng();
        *self.set.iter().choose(&mut rand::thread_rng()).unwrap()
    }
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */

fn main() {
    let obj = RandomizedSet::new();
    let mut val = 43
    let ret_1: bool = obj.insert(val);
    let ret_2: bool = obj.remove(val);
    let ret_3: i32 = obj.get_random();
}
