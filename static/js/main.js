// main.js
document.addEventListener('DOMContentLoaded', function () {
    console.log("Main.js loaded – Ready for interactivity.");
    
    // Example: Add form submission logging for the options page
    const optionsForm = document.querySelector('form');
    if (optionsForm) {
        optionsForm.addEventListener('submit', function (e) {
            console.log("Options form submitted.");
            // Add further client-side validation or interactivity here.
        });
    }
});

