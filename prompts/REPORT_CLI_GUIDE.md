# CLI Report Creation Guide (Reusable for Any Student/Project)

Use this file every time you need to create a project report using CLI + LaTeX/template.

---

## 1) What you need before starting

1. Project code folder (mandatory)
2. Student details (name, USN, course, date, etc.)
3. Optional template file (`.docx` or `.pdf`) if you want same style
4. Output screenshots (dashboard, API, DB queries, trigger proofs, etc.)
5. LaTeX installed (`xelatex` recommended)

---

## 2) Fill this input block first (copy and edit)

```text
COLLEGE NAME:
DEPARTMENT:
PROJECT TITLE:
COURSE CODE:
COURSE NAME:
SEMESTER & SECTION:
INSTRUCTOR NAME & DESIGNATION:
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

## 3) Choose one workflow

## A) You already have old report/template (PDF/DOCX)

Use this when you want same look/format.

1. Keep template file ready.
2. Ask CLI to preserve front/certificate pages exactly.
3. Replace names/course/project details.
4. Replace body content with new project sections.
5. Keep appendix at end (after references).

### Prompt for Workflow A

```text
Use this template file: <TEMPLATE_PATH>.
Keep first <N> pages exactly same style/layout.
Replace all project content with my new project.
Update front page, team members, certificates, course name, project title, submission date.
Generate final LaTeX + PDF.
Keep appendix after references.
```

---

## B) You only have code (no report/template)

1. Run project and DB.
2. Capture screenshots (UI + API + SQL output).
3. Ask CLI to generate full report structure from code.
4. Compile LaTeX and review.

### Prompt for Workflow B

```text
I only have project code at <PROJECT_PATH>.
Generate full report in LaTeX with:
- Title page
- Certificates (one per member)
- Abstract
- TOC
- Sections 1 to 7
- References
- Appendix with code listings
Use Times New Roman and proper academic format.
```

---

## 4) Recommended folder structure

```text
project-root/
  report/
    images/
    report.tex
    report.pdf
    template_first4.pdf   (if using hybrid template style)
  src/...
  sql/...
```

---

## 5) Useful PowerShell commands

```powershell
# Compile LaTeX (run twice for TOC/page refs)
xelatex -interaction=nonstopmode -halt-on-error report.tex
xelatex -interaction=nonstopmode -halt-on-error report.tex

# Copy final report
Copy-Item .\report.pdf "C:\Users\<you>\Desktop\FINAL_REPORT.pdf" -Force
```

---

## 6) Prompt library (copy-paste)

## Prompt 1: Update only names/course/date

```text
Update these fields everywhere:
- Team members:
  USN1 - NAME1
  USN2 - NAME2
  USN3 - NAME3
- Course name: <COURSE_NAME>
- Project title: <PROJECT_TITLE>
- Submission date: <DD/MM/YYYY>
Do not change other formatting.
```

## Prompt 2: Fix front-page alignment issue

```text
Front-page project title is misaligned.
Center it and keep same style.
Do not change certificate pages.
Rebuild PDF.
```

## Prompt 3: Fix header/footer style

```text
Remove image header/footer.
Use text header only: <PROJECT_TITLE>.
Footer left: Dept of <DEPT>, <COLLEGE>
Footer right: Page number.
Keep first 4 template pages unchanged.
```

## Prompt 4: Add more references + appendix check

```text
Add more references (books + official docs + URLs).
Ensure Appendix is after References.
Include full SQL and backend code listings in appendix.
```

---

## 7) Quality checklist before submission

1. Front page details correct (title, course, date, members)
2. One certificate page per member
3. Course/project name changed everywhere
4. Main headings and body font sizes match requirement
5. Page numbering correct
6. References present and sufficient
7. Appendix at end with code
8. Screenshots visible and captions correct
9. No broken names across lines on front page

---

## 8) For another student quickly

1. Copy this guide.
2. Replace input block values.
3. Reuse same prompts.
4. Point CLI to that student’s code/template path.
5. Regenerate PDF.

---

## 9) Important note

If institute format is strict, **always keep template front pages unchanged** and replace only content sections.

