# DSLR — DataScience × Logistic Regression

A Harry Potter–themed data science project that builds a **Sorting Hat** using one-vs-all logistic regression to classify Hogwarts students into their correct house based on course exam scores.

## Quick Start

```bash
# 1. Clone the repository
git clone <repository-url>
cd <repository-name>

# 2. Create virtual environment
python3 -m venv .venv

# 3. Activate virtual environment
source .venv/bin/activate

# 4. Install dependencies
pip install -r requirements.txt

# 5. Run the pipeline
python3 logreg_train.py dataset_train.csv
python3 logreg_predict.py dataset_test.csv weights.json
cat houses.csv
```

---

## Environment Setup (detailed)

### Prerequisites

- **Python 3.10+** (tested with 3.12)
- `python3` and `pip` available in `PATH`

### Step 1 — Create virtual environment

```bash
python3 -m venv .venv
```

This creates an isolated Python environment in the `.venv/` directory. It will not interfere with your system Python.

### Step 2 — Activate virtual environment

```bash
# Linux / macOS
source .venv/bin/activate

# Windows (PowerShell)
.venv\Scripts\Activate.ps1

# Windows (cmd)
.venv\Scripts\activate.bat
```

You should see `(.venv)` appear in your terminal prompt. All subsequent `python3` and `pip` commands will use the virtual environment.

### Step 3 — Install dependencies

```bash
pip install -r requirements.txt
```

This installs:
- `pandas` — data loading and manipulation
- `numpy` — numerical array operations
- `matplotlib` — plotting and visualisation
- `scikit-learn` — evaluation only (accuracy_score used by `evaluate.py`)

### Step 4 — Verify installation

```bash
python3 -c "import pandas, numpy, matplotlib; print('All dependencies OK')"
```

---

## Project Scripts

### V.1 — Data Analysis

```bash
python3 describe.py dataset_train.csv
```

Outputs descriptive statistics (count, mean, std, min, percentiles, max, and more) for all numeric columns. All statistics are hand-implemented — no built-in shortcuts.

### V.2 — Data Visualisation

```bash
# V.2.1 — Histogram: which course has homogeneous distribution across houses?
python3 histogram.py dataset_train.csv

# V.2.2 — Scatter plot: which two features are most similar?
python3 scatter_plot.py dataset_train.csv

# V.2.3 — Pair plot: which features to use for logistic regression?
python3 pair_plot.py dataset_train.csv                    # grid view (default)
python3 pair_plot.py dataset_train.csv -p panel           # panel view
python3 pair_plot.py dataset_train.csv -s pair_plot.png   # save to file
```

### V.3 — Logistic Regression

#### Training

```bash
# Default: batch gradient descent, 1000 epochs, lr=0.1
python3 logreg_train.py dataset_train.csv

# Stochastic gradient descent (bonus)
python3 logreg_train.py dataset_train.csv --optimizer sgd --lr 0.01 --epochs 500

# Mini-batch gradient descent (bonus)
python3 logreg_train.py dataset_train.csv --optimizer minibatch --batch-size 64 --epochs 500

# Automatic feature selection (bonus)
python3 logreg_train.py dataset_train.csv --auto-select

# Custom output path
python3 logreg_train.py dataset_train.csv -o my_weights.json

# Run 5-fold cross-validation to verify the model generalises (diagnostic)
python3 logreg_train.py dataset_train.csv --cross-validate
```

**Output**: `weights.json` (learned model weights and preprocessing parameters)

#### Prediction

```bash
python3 logreg_predict.py dataset_test.csv weights.json
```

**Output**: `houses.csv` with predicted house labels:
```
Index,Hogwarts House
0,Hufflepuff
1,Ravenclaw
2,Gryffindor
...
```

#### Evaluation

Mirrors the evaluator's process using scikit-learn's `accuracy_score`:

```bash
# Compare predictions against a truth file
python3 evaluate.py houses.csv truth.csv
```

For self-testing (when you don't have the ground truth for the test set), predict on the training data and evaluate against it:

```bash
python3 logreg_train.py dataset_train.csv
python3 logreg_predict.py dataset_train.csv weights.json -o houses_train.csv
python3 evaluate.py houses_train.csv dataset_train.csv
```

Output includes sklearn's accuracy score, pass/fail against the 98% threshold, and a per-house classification report (precision, recall, f1-score).

#### Full CLI reference

```
logreg_train.py [-h] [--optimizer {batch,sgd,minibatch}] [--lr LR]
                [--epochs EPOCHS] [--batch-size BATCH_SIZE]
                [--auto-select] [--cross-validate] [--output OUTPUT] FILE

logreg_predict.py [-h] [--output OUTPUT] FILE WEIGHTS

evaluate.py PREDICTIONS TRUTH
```

---

## Project Structure

```
.
├── describe.py              # V.1  Custom describe() implementation
├── histogram.py             # V.2.1 Homogeneous course histogram
├── scatter_plot.py          # V.2.2 Most similar features scatter plot
├── pair_plot.py             # V.2.3 Pair plot / scatter matrix
├── plot_utilities.py        # Shared utilities for V.2 scripts
├── math_utils.py            # V.3  Sigmoid, cost, gradient functions
├── logreg_train.py          # V.3  Train one-vs-all logistic regression
├── logreg_predict.py        # V.3  Predict houses from trained model
├── evaluate.py              # Accuracy evaluation using sklearn
├── dataset_train.csv        # Training data (1600 labelled students)
├── dataset_test.csv         # Test data (400 students, labels hidden)
├── requirements.txt         # Python dependencies
```

---

## Accuracy

| Metric | Value |
|--------|-------|
| Training accuracy (batch GD) | **98.19%** |
| 5-fold cross-validation mean | **98.19%** |
| Project requirement | ≥ 98% |

---

## Authors

- **doriani** — doriani@student.42roma.it
- **gmartin** — gmartin@student.42roma.it
