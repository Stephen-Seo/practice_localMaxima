use structopt::StructOpt;

#[derive(StructOpt, Debug)]
#[structopt(name = "LocalMaxima")]
struct Opts {
    input: Vec<i32>,
}

fn main() {
    let opts = Opts::from_args();
    let mut consecutive = false;
    for i in 1..opts.input.len()-1 {
        if opts.input[i-1] <= opts.input[i] && opts.input[i] >= opts.input[i+1] {
            if !consecutive {
                print!("{} ", opts.input[i]);
                consecutive = true;
            }
        } else {
            consecutive = false;
        }
    }
}
