# ft_package

A simple Python package for counting items in lists.

## Installation

You can install the package using pip:
```bash
pip install ./dist/ft_package-0.0.1.tar.gz
# or
pip install ./dist/ft_package-0.0.1-py3-none-any.whl
```
## Usage

```python
from ft_package import count_in_list

# Count occurrences of an item in a list
result = count_in_list(["toto", "tata", "toto"], "toto")
print(result)  # Output: 2

result = count_in_list(["toto", "tata", "toto"], "tutu")
print(result)  # Output: 0
```
## Features

Simple and intuitive API
Lightweight with no external dependencies
Well-documented with examples
Comprehensive error handling

## Requirements

Python 3.7 or higher

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Author

doriani - doriani@student.42roma.it