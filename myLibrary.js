function makeAlert(text) {
    alert(text);
}

if (typeof mergeInto !== 'undefined') mergeInto(LibraryManager.library, {
    testExternalJSMethod: function() {
        makeAlert("Hello world");
    }
});

