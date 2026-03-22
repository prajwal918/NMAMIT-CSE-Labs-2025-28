# All CLI TeX-to-PDF Prompt (Best Version) + Why

This prompt style is based on your existing repo prompt files:
- `ocr_prompt.md` -> fix only requested scope
- `dbms_prompt.md` -> step-by-step workflow + validation
- `sepm_prompt.md` -> strict source-only content

## Master Prompt (Use in Copilot / Claude / Gemini)

I have source files in `<INPUT_FOLDER>` (PDF/images/text) for `<SUBJECT>`.

Use only these source files. Do not use outside references.

Create `<OUTPUT_NAME>.tex` and `<OUTPUT_NAME>.pdf` in `<OUTPUT_FOLDER>`.

Requirements:
1. Preserve original meaning, values, identifiers, formulas, and section order.
2. Clean OCR mistakes and formatting noise only.
3. Use common LaTeX packages (`geometry`, `amsmath`, `graphicx`, `hyperref`, `listings` as needed).
4. Keep output exam-ready and readable with clear headings/subheadings.

Execution steps:
1. Read all files in `<INPUT_FOLDER>`.
2. Extract only content relevant to `<SUBJECT>`.
3. Build structured LaTeX in `<OUTPUT_NAME>.tex`.
4. Compile with `pdflatex` twice.
5. If compile fails, fix TeX errors and retry until successful PDF generation.

Final output:
- Print exact paths of `.tex` and `.pdf`.
- Print a short validation summary (compile success + page count).

## Why this prompt is written this way

1) "Use only these source files"
- Prevents drift/hallucinated additions.
- Same strict rule style as `sepm_prompt.md`.

2) "Preserve meaning, values, identifiers..."
- Protects technical correctness (SQL/math/code/marks).
- Same fidelity principle as `dbms_prompt.md`.

3) "Clean OCR mistakes only"
- Avoids unnecessary rewriting.
- Matches `ocr_prompt.md` intent.

4) "Common LaTeX packages"
- Reduces package-not-found and compatibility compile failures.

5) "Compile with pdflatex twice"
- Stabilizes references/TOC and output layout.

6) "Retry until successful PDF"
- Forces completion instead of stopping at first error.

7) "Print paths + validation summary"
- Gives quick proof that task finished correctly.

## CLI-specific add-ons (optional)

### Copilot CLI
Use the Master Prompt directly.

### Claude Code
Use Master Prompt + add: `Do not change files outside <OUTPUT_FOLDER>.`

### Gemini CLI
Use Master Prompt + add: `Show concise build log and final status.`
