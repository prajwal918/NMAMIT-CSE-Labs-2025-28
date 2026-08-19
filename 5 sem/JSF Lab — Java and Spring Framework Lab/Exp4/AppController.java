package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class AppController {
    @Autowired
    StaffManager manager;

    @GetMapping("/")
    public String showHomePage(Model model) {
        model.addAttribute("stafflist", manager.getAllStaff());
        return "index";
    }

    @GetMapping("/new")
    public String showCreatePage() {
        return "create_book_form";
    }

    @PostMapping("/save")
    public String saveStaff(@ModelAttribute Staff staff) {
        manager.saveStaff(staff);
        return "redirect:/";
    }

    @GetMapping("/edit/{id}")
    public String editStaff(@PathVariable Long id, Model model) {
        model.addAttribute("staff", manager.getStaffById(id));
        return "edit_form";
    }

    @GetMapping("/delete/{id}")
    public String deleteStaff(@PathVariable Long id, Model model) {
        manager.deleteStaff(id);
        return "redirect:/";
    }
}
