import os


def ft_tqdm(lst: range) -> None:
    n = len(lst)
    if n == 0:
        os.write(1, b"0%|[----------------------------------------] 0/0\n")
        return
    term_width = os.get_terminal_size().columns
    overhead = len(f"100%|| {len(lst)}/{len(lst)} [00:00<00:00, 000.00it/s]")
    bar_len = max(10, term_width - overhead)

    for i, item in enumerate(lst, 1):
        pct = i / n
        filled = int(bar_len * pct)
        bar = "█" * filled + " " * (bar_len - filled)
        output = f"\r{int(pct * 100)}%|{bar}| {i}/{n}"
        os.write(1, output.encode())
        yield item
    os.write(1, b"\n")
