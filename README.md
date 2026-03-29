# Mini-ATS-resume-scorer
# Mini ATS Resume Scorer

**Mini ATS Resume Scorer** is a lightweight **Applicant Tracking System (ATS) simulator** that analyzes resumes and generates compatibility scores against specific job roles. This project helps users understand how well their resume will perform in real ATS software used by recruiters.

This project was developed as part of a **PBL Hackathon** and demonstrates a complete flow from **resume upload to ATS scoring** with a clean, interactive frontend.

---

## Team Members and Contributions

| Member | Contribution |
|--------|-------------|
| **Antra** | File handling module, connecting all modules, PDF/DOCX text extraction, preprocessing, input/output integration,front |
| **Member 2** | Keyword extraction module, text cleaning, parsing resumes to extract skills |
| **Member 3** | String matching , identifying missing skills |
| **Member 4** |  scoring module, computing ATS match percentage, |

> Each module was developed independently and integrated through standardized inputs/outputs to ensure smooth pipeline execution.

---

## Features

- **Resume Upload & Conversion**: Accepts PDF/DOCX resumes and converts them to plain text for processing.
- **Job Role Matching**: Compare resumes with predefined job descriptions (Software Developer, Web Developer, Data Analyst).
- **Keyword Extraction & Skill Matching**: Extracts skills from resumes and compares them with job requirements.
- **ATS Score Generation**: Generates a compatibility score with a **progress bar**, **matched/missing skills**, and **improvement suggestions**.
- **Frontend Dashboard**: Clean, dark-themed interface for uploading resumes, selecting job roles, and viewing results with dynamic animations.

---

## Tech Stack

- **Backend**: C (File handling, keyword extraction, skill matching, scoring)
- **Frontend**: HTML, CSS, JavaScript
- **Tools**: `pdftotext` for PDF to text conversion

---

## How It Works

1. **Upload Resume** – Users upload their resume in PDF/DOCX format.
2. **Job Role Selection** – Choose the job role for comparison.
3. **Text Extraction** – Resume is converted to plain text.
4. **Skill Matching** – Extracted skills are compared with the job description.
5. **Score Generation** – ATS compatibility score is calculated and displayed along with matched and missing skills and improvement tips.

---
