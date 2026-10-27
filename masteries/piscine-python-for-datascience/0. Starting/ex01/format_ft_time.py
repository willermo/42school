import time

now = time.time()
fixed = f"{now:,.4f}"
print("Seconds since January 1, 1970:", end=' ')
print(f"{fixed} or {now:.2e} in scientific notation")
