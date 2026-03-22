# All CLI TeX-to-PDF Prompt Pack

Use these exact prompts in each CLI.

## Copilot CLI Prompt

Read all PDFs and images from `<INPUT_FOLDER>`. Extract only content related to `<SUBJECT_OR_TASK>`. Build a clean structured draft with headings. Generate LaTeX file `<OUTPUT_NAME>.tex` using standard packages only. Compile with `pdflatex` twice. If compile fails, fix errors and recompile until PDF is generated. Save final files as `<OUTPUT_NAME>.tex` and `<OUTPUT_NAME>.pdf` in `<OUTPUT_FOLDER>`. Print final output paths.

## Claude Code Prompt

Process every PDF/image in `<INPUT_FOLDER>` for `<SUBJECT_OR_TASK>`. Create a single polished LaTeX document named `<OUTPUT_NAME>.tex`. Preserve section order and remove OCR noise. Compile to PDF using `pdflatex` twice. If LaTeX errors occur, patch the tex and retry until successful PDF generation. Save outputs in `<OUTPUT_FOLDER>` and print file paths.

## Gemini CLI Prompt

Take all files in `<INPUT_FOLDER>` and convert relevant content for `<SUBJECT_OR_TASK>` into LaTeX. Output `<OUTPUT_NAME>.tex`, then compile to `<OUTPUT_NAME>.pdf` using `pdflatex` twice. If errors appear, fix the `.tex` and re-run until success. Use only common LaTeX packages. Save everything in `<OUTPUT_FOLDER>` and print final paths.

## Universal Prompt (works in any CLI)

Read all PDFs/images in `<INPUT_FOLDER>`. Extract only `<SUBJECT_OR_TASK>`. Create `<OUTPUT_NAME>.tex` with clear sections and common LaTeX packages. Compile with `pdflatex` twice. If compile errors appear, fix and retry until `<OUTPUT_NAME>.pdf` is generated. Save both files in `<OUTPUT_FOLDER>` and print final paths.
