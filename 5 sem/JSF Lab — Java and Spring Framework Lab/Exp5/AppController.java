package com.example.demo;

import java.util.List;
import java.util.NoSuchElementException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class AppController {
    @Autowired
    StaffManager manager;

    @GetMapping("/staff")
    public List<Staff> listAllStaff() {
        return manager.getAllStaff();
    }

    @GetMapping("/staff/{id}")
    public ResponseEntity<Staff> getStaff(@PathVariable Long id) {
        try {
            Staff staff = manager.getStaffById(id);
            return new ResponseEntity<Staff>(staff, HttpStatus.OK);
        } catch(NoSuchElementException e) {
            return new ResponseEntity<Staff>(HttpStatus.NOT_FOUND);
        }
    }

    @PostMapping("/staff")
    public void saveStaff(@RequestBody Staff staff) {
        manager.saveStaff(staff);
    }

    @PutMapping("/staff")
    public void updateStaff(@RequestBody Staff staff) {
        manager.saveStaff(staff);
    }

    @DeleteMapping("/staff/{id}")
    public ResponseEntity<Staff> deleteStaff (@PathVariable Long id) {
        if(manager.exists(id)) {
            manager.deleteStaff(id);
            return new ResponseEntity<Staff>(HttpStatus.OK);
        } else {
            return new ResponseEntity<Staff>(HttpStatus.NOT_FOUND);
        }
    }
}
