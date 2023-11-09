function addTask() {
    const task = prompt("add:");
    
    if (task) {
        const list = document.querySelector("#list");
        const item = document.createElement("li");

        const buttonEdit = document.createElement('button');
        buttonEdit.textContent = 'edit';
        buttonEdit.classList.add('editButton');
        buttonEdit.addEventListener("click", (event) => {
            const taskEdit = prompt("edit:", event.target.parentNode.firstChild.textContent);

            if (taskEdit) {
                event.target.parentNode.firstChild.textContent = taskEdit;
            }
        })

        const buttonDelete = document.createElement('button');
        buttonDelete.textContent = 'delete';
        buttonDelete.classList.add('deleteButton');
        buttonDelete.addEventListener("click", () => {
            list.removeChild(item);
        })

        const checkbox = document.createElement("input");
        checkbox.type = "checkbox";
        checkbox.classList.add('check');
        checkbox.addEventListener("change", () => {
            if (checkbox.checked) {
                item.classList.add("completed");
            }
            else {
                item.classList.remove("completed");
            }
        })

        list.appendChild(item);
        
        item.appendChild(document.createTextNode(task));
        item.appendChild(buttonEdit);
        item.appendChild(buttonDelete);
        item.appendChild(checkbox)
    }
}