# React + Vite Guide for College Report + PPT (CLI Workflow)

Use this when you want a faster alternative to LaTeX for:
1. **Project report (PDF)**
2. **Presentation slides (PPT/PDF)**

---

## 0) Best method when you need exact DOCX replica

If your main goal is **exact same Word template look** (page breaks, alignment, certificate style, front page spacing):

1. **Best:** DOCX templating (Docxtemplater / Aspose.Words)
2. **Second:** Word automation + placeholder replacement
3. **Then:** React + Vite + PDF export (good for design speed, not exact Word fidelity)
4. **Then:** LaTeX (excellent academic layout, but not exact Word replica)

So for strict replica requirements, use React/Vite for workflow UI if needed, but generate final report from a DOCX template pipeline.

---

## 1) When React + Vite is a good choice

Use React + Vite if you need:
- quick visual edits
- reusable templates for many students
- same design reused across report + slides
- easier image/chart embedding

Use LaTeX only when your college strictly demands LaTeX-style academic formatting.

---

## 2) What final files you should submit

Most colleges expect:
1. **Report:** PDF (or DOCX)
2. **Presentation:** PPTX (or PDF slides)

So React + Vite is used to **generate clean content**, then export to final formats.

---

## 3) Quick setup (one-time)

```powershell
npm create vite@latest report-ppt -- --template react
cd report-ppt
npm install
npm install react-router-dom
npm install -D playwright
npx playwright install chromium
```

Optional for PPTX generation:

```powershell
npm install pptxgenjs
```

---

## 4) Recommended folder structure

```text
report-ppt/
  src/
    report/
      ReportPage.jsx
      sections/
        Intro.jsx
        Problem.jsx
        Objectives.jsx
        Methodology.jsx
        Implementation.jsx
        Results.jsx
        Conclusion.jsx
        References.jsx
        Appendix.jsx
    slides/
      SlidesPage.jsx
      slidesData.js
    assets/
      logo.png
      screenshots/
  scripts/
    export-report-pdf.mjs
    export-slides-pdf.mjs
  public/
  package.json
```

---

## 5) Routing model

Create 2 routes:
- `/report` → full report page
- `/slides` → presentation slides page

Example (concept):

```jsx
<Routes>
  <Route path="/report" element={<ReportPage />} />
  <Route path="/slides" element={<SlidesPage />} />
</Routes>
```

---

## 6) Typography rules (recommended for report page)

- Font: Times New Roman
- Heading: 16 bold
- Body: 16 normal
- Line spacing: 1.5
- A4 print width style for report container

Use a dedicated CSS file for print-safe layout.

---

## 7) Export report to PDF (best way)

Use Playwright to open `/report` and print PDF.

Create `scripts/export-report-pdf.mjs`:

```js
import { chromium } from "playwright";

const browser = await chromium.launch();
const page = await browser.newPage();
await page.goto("http://localhost:5173/report", { waitUntil: "networkidle" });
await page.pdf({
  path: "Report_Final.pdf",
  format: "A4",
  printBackground: true,
  margin: { top: "20mm", right: "15mm", bottom: "20mm", left: "15mm" }
});
await browser.close();
```

Run:

```powershell
npm run dev
node scripts/export-report-pdf.mjs
```

---

## 8) Export slides for presentation

## Option A (Fast): PDF slides

Create a `/slides` route where each slide is 16:9 block and export with Playwright to PDF.

## Option B (Best for college): PPTX

Use `pptxgenjs` and generate real `.pptx` from `slidesData.js`.

---

## 9) If you have only code (no old report)

Workflow:
1. Run project and DB.
2. Capture screenshots (dashboard, APIs, SQL outputs, trigger proofs).
3. Write sections in `src/report/sections/*`.
4. Export report PDF.
5. Create 8–12 slides in `/slides`.
6. Export slides PDF/PPTX.

---

## 10) If you have existing template (old PDF/DOCX)

Workflow:
1. Extract style elements (logo, header, footer colors, section spacing).
2. Recreate same look in React components/CSS.
3. Keep old structure:
   - Title page
   - Certificates
   - Abstract
   - TOC
   - Sections 1–7
   - References
   - Appendix
4. Replace only content for new student/project.

---

## 11) Reusable input block (fill this first)

```text
COLLEGE NAME:
DEPARTMENT:
PROJECT TITLE:
COURSE CODE:
COURSE NAME:
SEMESTER & SECTION:
INSTRUCTOR NAME:
TEAM MEMBERS (USN - NAME):
ACADEMIC YEAR:
DATE OF SUBMISSION:

ABSTRACT:
INTRODUCTION:
PROBLEM STATEMENT:
OBJECTIVES:
METHODOLOGY:
IMPLEMENTATION DETAILS:
RESULTS:
CONCLUSION:
REFERENCES:
APPENDIX/CODE:
```

---

## 12) Copy-paste prompts for CLI

## Prompt: Build report + slides from code

```text
Create a React+Vite report and slides system from this project path: <PATH>.
Add /report and /slides routes.
Use Times New Roman, heading 16 bold, body 16 normal.
Include title, certificate pages, abstract, TOC, sections 1-7, references, appendix.
Add Playwright export scripts for report PDF and slides PDF.
```

## Prompt: Update for another student quickly

```text
Reuse the same React+Vite template.
Replace all student/course/project details with:
<PASTE INPUT BLOCK>
Keep design unchanged.
Regenerate report PDF and slides PDF/PPT.
```

## Prompt: Template-matching mode

```text
Match this old report template style from file: <TEMPLATE_PATH>.
Keep same visual style but update all content for this new project.
Generate report PDF and slide deck.
```

---

## 13) QA checklist before submission

1. Front page details correct
2. Team names/USNs correct everywhere
3. Certificate pages count = number of members
4. Course name/project name consistent across report + slides
5. References section is complete
6. Appendix at end with full code
7. Screenshots clear and readable
8. PDF opens correctly on another machine

---

## 14) Suggested output naming

- `REPORT_<PROJECT>_<DATE>.pdf`
- `PPT_<PROJECT>_<DATE>.pptx`
- `PPT_<PROJECT>_<DATE>.pdf`

This keeps versioning clean for multiple students.

