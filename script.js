function startScan(){

let file=document.getElementById("resumeFile").files[0];

if(!file){
alert("Please upload a resume first.");
return;
}

document.getElementById("scanBox").style.display="block";

let scanText=document.getElementById("scanText");

setTimeout(()=>{
scanText.innerText="Extracting Skills...";
},600);

setTimeout(()=>{
scanText.innerText="Matching with Job Description...";
},1200);

setTimeout(()=>{
scanText.innerText="Generating ATS Score...";
},1700);

setTimeout(()=>{
window.location.href="result.html";
},2200);

}

function goHome(){
window.location.href="index.html";
}

function showInfo(){

let section=document.getElementById("systemInfo");

section.style.display="block";

window.scrollTo({
top:section.offsetTop,
behavior:"smooth"
});

}

document.getElementById("resumeFile")?.addEventListener("change",function(){

let fileName=this.files[0].name;
document.getElementById("fileName").innerText="Selected File: "+fileName;

});

let dropArea=document.querySelector(".drop-area");

dropArea?.addEventListener("dragover",(e)=>{
e.preventDefault();
dropArea.style.borderColor="#22c55e";
});

dropArea?.addEventListener("dragleave",()=>{
dropArea.style.borderColor="#38bdf8";
});

dropArea?.addEventListener("drop",(e)=>{
e.preventDefault();
document.getElementById("resumeFile").files=e.dataTransfer.files;
});

window.onload=function(){

let bar=document.getElementById("scoreBar");
let text=document.getElementById("scoreText");

if(bar){

let score=78;

setTimeout(function(){

bar.style.width=score+"%";
text.innerHTML=score+"%";

if(score<50){
bar.style.background="#ef4444";
text.style.color="#ef4444";
}
else if(score<75){
bar.style.background="#facc15";
text.style.color="#facc15";
}

},500);

}

let matched=["Java","Data Structures","Git"];
let missing=["SQL","Algorithms","System Design"];

let matchList=document.getElementById("matchedSkills");
let missList=document.getElementById("missingSkills");

if(matchList){

matched.forEach(skill=>{
let li=document.createElement("li");
li.textContent=skill;
matchList.appendChild(li);
});

missing.forEach(skill=>{
let li=document.createElement("li");
li.textContent=skill;
missList.appendChild(li);
});

}

};