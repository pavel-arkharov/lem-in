# AI-Native Workflow: Enhancing Lem-in with LLMs

This project is designed to be part of an AI-native engineering workflow. Below are examples of how to use Large Language Models (LLMs) to enhance the development and testing of this pathfinding engine.

## 1. AI-Assisted Map Generation

Use the following prompt to generate complex, edge-case maps for testing:

> "Act as a systems test engineer. Generate a lem-in map file with 50 rooms. The map should have two primary paths from ##start to ##end: one path is very short (3 steps) but narrow (capacity of 1), and another path is longer (10 steps) but has 3 parallel vertex-disjoint routes. The goal is to test the algorithm's ability to balance path length vs. total throughput for 100 ants. Output in the lem-in map format."

## 2. Performance Analysis via JSON

With the `-j` (JSON) flag, you can pipe the engine's output directly into an LLM for strategic analysis:

```bash
./lem-in -j < maps/complex.map > result.json
```

**Prompt for Analysis:**
> "Analyze this JSON output from my ant-farm optimizer. Calculate the efficiency of the ant distribution across paths. Are there any bottlenecks where ants are waiting unnecessarily? Suggest if a different path combination could have reduced the total turn count."

## 3. Automated Refactoring & Porting

The core algorithm is written in C for performance. For rapid prototyping of new heuristics, use an LLM to port the `solve()` and `optimise_flow()` logic to Python:

**Prompt:**
> "Port the following C function `optimise_flow` to idiomatic Python using the `networkx` library. Maintain the Edmonds-Karp logic but optimize for readability."

---

*This approach demonstrates the integration of low-level systems programming with modern AI-orchestrated workflows.*
