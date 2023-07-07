#!/usr/bin/env python3
import os

i = 1
while i < 2000:
    print(f"\npage num {i}")
    val = os.system(f"./tlb {i} 10000")
    i *= 2

