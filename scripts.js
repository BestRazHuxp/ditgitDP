document.getElementById("searchButton").addEventListener("click", function() {
    // Get the input value
    const searchTerm = document.getElementById("searchInput").value.toLowerCase().trim();
    
    // Get the main content where the search will be performed
    const content = document.getElementById("main-content");
    
    // Clear previous highlights
    const highlighted = content.querySelectorAll(".highlight");
    highlighted.forEach(function(el) {
        el.classList.remove("highlight");
        el.outerHTML = el.textContent; // Remove highlight but keep the text intact
    });
    
    if (searchTerm === "") {
        alert("Vui lòng nhập từ khóa để tìm kiếm.");
        return;
    }

    // Search and highlight
    let found = false;
    const innerHTML = content.innerHTML;
    
    const searchRegex = new RegExp(searchTerm, "gi");
    const newInnerHTML = innerHTML.replace(searchRegex, function(match) {
        found = true;
        return `<span class="highlight">${match}</span>`;
    });

    content.innerHTML = newInnerHTML;
    
    if (!found) {
        alert("Không tìm thấy từ khóa.");
    }
});

document.getElementById("darkModeToggle").addEventListener("click", function() {
    const body = document.body;
    
    // Toggle between dark mode and light mode
    if (body.classList.contains("light-mode")) {
        body.classList.remove("light-mode");
        body.classList.add("dark-mode");
        this.textContent = "Light Mode"; // Change button text
    } else {
        body.classList.remove("dark-mode");
        body.classList.add("light-mode");
        this.textContent = "Dark Mode"; // Change button text
    }
});

