import subprocess
import os
import sys
import logging
from argparse import ArgumentParser, Namespace
from pathlib import Path
from tqdm import tqdm

def main(args: Namespace) -> None:
    if args.problem_number is None:
        raise ValueError("Please provide a problem number")
    base_data_path = os.path.expanduser(f"{args.output_dir}/{args.problem_number}") 

    # Compile the C program
    logging.info("Compiling the C program...")
    compile_command = ["gcc", "main.c", "-o", "main"]
    subprocess.run(compile_command, check=True)

    # Run the compiled program with each input file and compare the output
    logging.info("Running the compiled program...")
    for i in tqdm(range(10)):
        in_file = os.path.join(base_data_path, f"{i}.in")
        out_file = os.path.join(base_data_path, f"{i}.out")
        gen_out_file = os.path.join(base_data_path, f"gen_{i}.out")

        # Run the program with the input file
        with open(in_file, "r") as in_f, open(gen_out_file, "w") as out_f:
            run_command = ["./main"]
            subprocess.run(run_command, stdin=in_f, stdout=out_f, check=True)

        # Compare the generated output with the expected output
        diff_command = ["diff", gen_out_file, out_file]
        result = subprocess.run(diff_command, stdout=subprocess.PIPE)

        # If the diff command output is not empty, there's a difference
        if result.stdout:
            logging.warning(f"Warning: Differences detected in the output for input {in_file}")


def parse_args() -> Namespace:
    parser = ArgumentParser()
    parser.add_argument(
        "--problem_number",
        type=int,
        help="Problem Number.",
    )
    parser.add_argument(
        "--output_dir",
        type=Path,
        help="Directory to save the output data.",
        default="./data/",
    )
    args = parser.parse_args()
    return args

if __name__ == "__main__":
    args = parse_args()
    main(args)
