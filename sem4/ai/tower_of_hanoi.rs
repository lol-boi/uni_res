//shift n-1 disks form A to B using C
//shift last disk form A to C
//shift n-1 disks form B to C using A

fn towerofhanoi(n:u8, from_rod: char, to_rod:char, aux_rod:char){
    if n==0 {
        return;
    }    
    towerofhanoi(n-1,from_rod,aux_rod,to_rod);
    println!("Move disk {} from {} to {}",n, from_rod, to_rod);
    towerofhanoi(n-1,aux_rod, to_rod, from_rod); 
}


fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();  //read input line string and store it 
    let disks: u8 = line.trim().parse().unwrap(); //convet line into intiger
    towerofhanoi(disks,'A','C','B');
    return; 
}
