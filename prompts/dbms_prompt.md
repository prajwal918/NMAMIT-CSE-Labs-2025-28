# DBMS Lab Manual Accuracy Prompt (Exact-Quality Workflow)

Use this prompt when recreating DBMS lab manuals from photos/PDF with high accuracy.

---

## Objective
Recreate a DBMS lab manual with **maximum possible accuracy** from the provided notebook images/PDF, including:
- typed content,
- correct SQL,
- proper ordering,
- clean PDF output,
- and (if needed) exact diagram appearance.

---

## Inputs (mandatory)
1. Source images (WhatsApp/photos) or source merged PDF.
2. Target output folder.
3. Requirement mode:
   - `exact-visual` (same look as source pages),
   - `fully-typed` (typed content with clean layout),
   - or `hybrid` (typed text + exact image diagrams).

---

## Non-negotiable rules
1. **Do not change scope** without user request.
2. Preserve question intent, data values, SQL identifiers, and table names.
3. Do not “improve” SQL semantics unless explicitly asked.
4. Keep file changes limited to requested folder/files only.
5. Validate output before final handoff.

---

## Step-by-step workflow

### Step 1: Collect and order source pages
- Detect all images (`*.jpeg, *.jpg, *.png, *.webp, *.jfif`).
- Sort by timestamp in filename (including duplicate suffix `(1)`, `(2)`, etc.).
- Confirm final ordered list with page index.

### Step 2: Build source PDF (if images are source)
- Merge all ordered images into one PDF.
- Enforce **1 image = 1 page**.
- Verify:
  - image count == PDF page count,
  - output file exists and size is non-zero.

### Step 3: Extract text (OCR)
- Run OCR on all pages.
- Save OCR output page-by-page into text artifact.
- Keep raw OCR output for traceability.
- If OCR quality is low, run enhanced preprocessing pass (scale, grayscale, contrast, threshold) and keep best candidate.

### Step 4: Draft LaTeX content
- Create `lab_manual.tex`.
- Structure by experiments/sections exactly as source.
- Include:
  - schema definitions,
  - SQL DDL,
  - inserts,
  - query blocks,
  - results sections.
- Preserve case and identifier spellings from source where possible.

### Step 5: Diagram strategy decision
- If user wants **exact look**, embed original diagram images directly.
- If user wants **typed clean**, redraw in TikZ/UML.
- If user wants notebook style, add features like:
  - double-line entity boxes,
  - attribute ellipses,
  - relationship diamonds.

### Step 6: Compile and fix
- Compile with `xelatex` (or available engine).
- Resolve compilation errors only in touched files.
- Recompile until stable PDF is produced.

### Step 7: Accuracy QA (critical)
- Compare output against source page-by-page:
  - question statements,
  - SQL commands,
  - table/column names,
  - constants, dates, numbers, IDs.
- Run focused “query fidelity” pass:
  - no unintended SQL changes,
  - no renamed identifiers.

### Step 8: Produce variants when useful
- `lab_manual.pdf` → exact visual match version.
- `lab_manual_clean_uml.pdf` → clean typed diagram version.
- Keep both if user may need both.

### Step 9: Final validation checklist
- [ ] Required files exist.
- [ ] PDF opens.
- [ ] Page count validated.
- [ ] Requested mode satisfied (`exact-visual` / `fully-typed` / `hybrid`).
- [ ] No unrelated files modified.

---

## Suggested output files
- `merged_images_ordered.pdf`
- `lab_manual.tex`
- `lab_manual.pdf`
- `lab_manual_clean_uml.tex` (optional)
- `lab_manual_clean_uml.pdf` (optional)
- `ocr_output.txt` (artifact)

---

## Commit/push safety rules (if repo task)
1. Stage only intended files.
2. Check `git status` before commit.
3. Commit message should clearly state scope.
4. Push only after confirming no unrelated changes are included.

---

## Handoff format
When done, report:
1. What was created/updated.
2. Exact file paths.
3. Validation results (page count, compile success).
4. Any known limitations (e.g., OCR ambiguity) with clear note.

---

## Ready-to-use command intent summary
“Recreate my DBMS lab manual from source images/PDF with strict fidelity. Keep SQL exact, preserve order, compile to PDF, leave no unrelated changes, and provide both exact and clean variants if requested.”

