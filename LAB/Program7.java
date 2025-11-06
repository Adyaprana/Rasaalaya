// program 7 Reading Form Data via GET and POST
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/form-data")
public class FormDataServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String name = request.getParameter("name");
        String email = request.getParameter("email");

        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        out.println("<!DOCTYPE html>");
        out.println("<html><head><title>Form Data Using GET and POST</title></head><body>");
        out.println("<h3>Form submission using GET and POST (GET action form)</h3>");
        if (name != null && email != null) {
            out.println("<h4>Received Data (GET):</h4>");
            out.println("Name: " + name + "<br>");
            out.println("Email: " + email + "<br>");
            out.println("<hr>");
        }
        out.println("<form method='get' action='form-data'>");
        out.println("Name: <input type='text' name='name'><br>");
        out.println("Email: <input type='text' name='email'><br>");
        out.println("<input type='submit' value='Submit with GET'>");
        out.println("</form><hr>");
        out.println("<form method='post' action='form-data'>");
        out.println("Name: <input type='text' name='name'><br>");
        out.println("Email: <input type='text' name='email'><br>");
        out.println("<input type='submit' value='Submit with POST'>");
        out.println("</form>");
        out.println("</body></html>");
        out.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String name = request.getParameter("name");
        String email = request.getParameter("email");

        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        out.println("<!DOCTYPE html>");
        out.println("<html><head><title>Form Data Using GET and POST</title></head><body>");
        out.println("<h3>Form submission using GET and POST (POST action form)</h3>");
        if (name != null && email != null) {
            out.println("<h4>Received Data (POST):</h4>");
            out.println("Name: " + name + "<br>");
            out.println("Email: " + email + "<br>");
            out.println("<hr>");
        }
        out.println("<form method='get' action='form-data'>");
        out.println("Name: <input type='text' name='name'><br>");
        out.println("Email: <input type='text' name='email'><br>");
        out.println("<input type='submit' value='Submit with GET'>");
        out.println("</form><hr>");
        out.println("<form method='post' action='form-data'>");
        out.println("Name: <input type='text' name='name'><br>");
        out.println("Email: <input type='text' name='email'><br>");
        out.println("<input type='submit' value='Submit with POST'>");
        out.println("</form>");
        out.println("</body></html>");
        out.close();
    }
}