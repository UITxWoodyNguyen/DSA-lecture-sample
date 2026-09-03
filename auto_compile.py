#!/usr/bin/env python3
import os
import subprocess
import sys
from pathlib import Path


def find_cpp_files(root_dir):
    cpp_files = []
    for ext in ('*.cpp', '*.cc', '*.cxx', '*.c++'):
        cpp_files.extend(Path(root_dir).rglob(ext))
    return cpp_files


def compile_cpp(cpp_file, output_dir=None):
    if output_dir is None:
        output_dir = cpp_file.parent
    
    exe_name = cpp_file.stem + ('.exe' if sys.platform == 'win32' else '')
    exe_path = output_dir / exe_name
    
    cmd = ['g++', str(cpp_file), '-o', str(exe_path), '-std=c++17', '-Wall', '-Wextra']
    
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        if result.returncode == 0:
            print(f"[OK] Compiled: {cpp_file.name} -> {exe_name}")
            return exe_path
        else:
            print(f"[FAIL] Failed to compile {cpp_file.name}:")
            print(result.stderr)
            return None
    except subprocess.TimeoutExpired:
        print(f"[FAIL] Timeout compiling {cpp_file.name}")
        return None
    except FileNotFoundError:
        print("[FAIL] g++ not found. Please install g++ compiler.")
        return None


def run_executable(exe_path):
    try:
        result = subprocess.run([str(exe_path)], capture_output=True, text=True, timeout=10)
        if result.returncode == 0:
            print(f"  Output: {result.stdout.strip() or '(no output)'}")
        else:
            print(f"  Runtime error (exit code {result.returncode}): {result.stderr.strip()}")
    except subprocess.TimeoutExpired:
        print(f"  Timeout running executable")
    except Exception as e:
        print(f"  Error running executable: {e}")


def delete_executable(exe_path):
    try:
        exe_path.unlink()
        print(f"  Deleted: {exe_path.name}")
    except Exception as e:
        print(f"  Failed to delete {exe_path.name}: {e}")


def select_file(cpp_files):
    print("Available C++ files:")
    for i, f in enumerate(cpp_files, 1):
        print(f"  {i}. {f.relative_to(Path.cwd())}")
    
    while True:
        try:
            choice = input("\nSelect file number (or 'q' to quit): ").strip()
            if choice.lower() == 'q':
                return None
            idx = int(choice) - 1
            if 0 <= idx < len(cpp_files):
                return cpp_files[idx]
            print("Invalid selection. Try again.")
        except ValueError:
            print("Please enter a valid number.")
        except KeyboardInterrupt:
            print("\nCancelled.")
            return None


def main():
    repo_root = Path(__file__).parent
    cpp_files = find_cpp_files(repo_root)
    
    if not cpp_files:
        print("No C++ files found in repository.")
        return
    
    # If file specified as argument, use it directly
    if len(sys.argv) > 1:
        target = Path(sys.argv[1])
        if not target.is_absolute():
            target = repo_root / target
        
        # Find matching file
        matched = None
        for f in cpp_files:
            if f == target or f.name == target.name or f.stem == target.stem:
                matched = f
                break
        
        if matched:
            cpp_files = [matched]
        else:
            print(f"File not found: {sys.argv[1]}")
            print("Available files:")
            for f in cpp_files:
                print(f"  {f.relative_to(repo_root)}")
            return
    else:
        # Interactive selection
        selected = select_file(cpp_files)
        if not selected:
            return
        cpp_files = [selected]
    
    print()
    for cpp_file in cpp_files:
        print(f"Processing: {cpp_file.relative_to(repo_root)}")
        exe_path = compile_cpp(cpp_file)
        
        if exe_path and exe_path.exists():
            run_executable(exe_path)
            delete_executable(exe_path)
        print()


if __name__ == '__main__':
    main()